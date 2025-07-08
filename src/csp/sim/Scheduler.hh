
#include <functional>
#include <csp/base/types.hh>

namespace csp {

using SchedFunc = std::function<void(void)>;

// 1 tick equal to 1 ps, 1/1000 ns, 1/10^12 second.

// schedule timing: pre, at, post
enum SchedTiming {
    SchedAtTick, SchedPreTick, SchedPostTick
};

struct SchedEvent {
    SimObj   *sobj;
    SchedFunc cb_func;
    string    desc   = "";
    CB_Timing timing = CB_AtTick;
};

class EventQueue;
class Scheduler {
    long tick_ = 0;
    int  freq_mhz_ = 0;
    int  ticks_per_cycle_ = 0;
    EventQueue *equeue_;

public:
    Scheduler() {}
    Scheduler(int freq_mhz) { setFrequency(freq_mhz); }

    void setFrequency(int freq_mhz);

    long getCycle() const { return tick_ / ticks_per_cycle_; }
    long getTick()  const { return tick_; }

    void registerCycleFn(const SchedEvent &event);

    void callback     (int cyc_inc,  sptr<SchedEvent> event);
    void callbackTicks(int tick_inc, sptr<SchedEvent> event);
};

class SchedHelper {
    Scheduler *sched_;
    int cyc_delay_;
    sptr<SchedEvent> sevent_;
public:
    SchedHelper(Scheduler *sched, SimObj *sobj, string desc,
		int cyc_delay = -1,
		SchedFunc func = nullptr,
		SchedTiming timing = SchedAtTick)
	: sched_(sched), cycle_delay_(cyc_delay)
    {
	sevent_ = std::make_shared<SchedEvent>(sobj, desc, func, timing);
    }

    void callback(int cyc_delay = -1) const {
	if (cyc_delay == -1) cyc_delay = cyc_delay_;
	sched_->callback(cycle_delay, sevent_);
    }

    // higher cost
    void callback(int cyc_delay, SchedFunc func) const {
	auto e = std::make_shared<SchedEvent>(sevent_->sobj, sevent_->desc,
					      func, sevent_->timing);
	sched_->callback(cycle_delay, sevent_);
    }

};

}
