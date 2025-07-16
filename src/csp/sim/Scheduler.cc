
#include "Scheduler.hh"

#include <list>

namespace csp {

class EventQueues {
    using Event = sptr<SchedEvent>;
    using EventQ = std::list<Event>;

    EventQ events_pre_tick;
    EventQ events_at_tick;
    EventQ events_post_tick;

    EventQ *getEventQ(SchedTiming t) {
	EventQ *eq = nullptr;
	if      (t == SchedAtTick)   eq = &events_at_tick;
	else if (t == SchedPreTick)  eq = &events_pre_tick;
	else if (t == SchedPostTick) eq = &events_post_tick;
	return eq;
    }

    int ticks_per_cycle_;

public:
    EventQueues() {}
    void setTicksPerCycle(int tpc) { ticks_per_cycle_ = tpc; }

    void addEvent(Event &event) {
	auto *eq = getEventQ(event->timing);
	eq->push_back(event); // fixme, order
    }

    EventQ* getCloser(EventQ* qa, EventQ* qb) const {
	if (qa->empty())      return qb;
	else if (qb->empty()) return qa;
	else if (qa->front()->tick > qb->front()->tick) return qb;
	else return qa;
    }

    EventQ* getEventQNear() {
	EventQ *eq = getCloser(&events_pre_tick, &events_at_tick);
	eq = getCloser(eq, &events_post_tick);
	return eq;
    }

    long nextEventTick() {
	return getEventQNear()->front()->tick;
    }

    void invokeEvent(Event &e) {
	e->func();
	if (e->cycle_event) {
	    e->tick += ticks_per_cycle_;
	    addEvent(e);
	}
    }

    void invokeUntil(long tick) {
	while (true) {
	    auto *eq = getEventQNear();
	    if (eq->empty()) break;
	    if (eq->front()->tick > tick) break;
	    auto e = eq->front(); // fixme: copy element
	    eq->pop_front();
	    invokeEvent(e);
	}
    }
};

void Scheduler::registerCycleFn(const SchedEvent &_event)
{
    auto event = std::make_shared<SchedEvent>(_event);
    event->cycle_event = true;
    event->tick = getTick() + ticks_per_cycle_;
    equeues_->addEvent(event);
}

void Scheduler::callback(int cyc_inc,  sptr<SchedEvent> event)
{
    event->tick = getTick() + cyc_inc * ticks_per_cycle_;
    equeues_->addEvent(event);
}

void Scheduler::callbackTicks(int tick_inc, sptr<SchedEvent> event)
{
    event->tick = getTick() + tick_inc;
    equeues_->addEvent(event);
}

void Scheduler::advance(int nr_cycles)
{
    while (nr_cycles --) {
        tick_ += ticks_per_cycle_;
        equeues_->invokeUntil(getTick());
    }
}

void Scheduler::setFrequency(int freq_mhz)
{
    freq_mhz_ = freq_mhz;
    ticks_per_cycle_ = 1000000 / freq_mhz;
    equeues_->setTicksPerCycle(ticks_per_cycle_);
}

Scheduler::Scheduler(int freq_mhz) {
    equeues_ = new EventQueues();
    setFrequency(freq_mhz);
}

Scheduler::~Scheduler()
{
    delete equeues_;
}

}
