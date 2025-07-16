
#include <csp/base/types.hh>
#include <csp/sim/SimObj.hh>
#include <csp/sim/Scheduler.hh>
#include <csp/sim/Port.hh>

namespace csp {

class Module : public SimObj {
    Scheduler *sched_;
public:
    Module(Module *parent, const string &name)
	: SimObj(parent, name) {
	if (parent)
	    sched_ = parent->getSched();
    }

    // for root/top module
    Module(const string &name, Scheduler *sched)
	: SimObj(nullptr, name), sched_(sched) {
    }

    Scheduler *getSched() const { return sched_; }
    long getCycle() const { return sched_->getCycle(); }

    // set scheduler recursively
    void setSchedAll(Scheduler *sched);

    virtual string getModuleName() const {
	return "NoName";
    }

    // return a copy of children vector
    StdVector<Module*> getSubModules() const;

    virtual Port* getPort(const string& name) const;

};

}
