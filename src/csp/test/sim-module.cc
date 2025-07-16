
#include <csp/sim/Module.hh>

#include <iostream>

using namespace csp;

class ModuleA : public Module {
public:
    ModuleA(const string &name, Scheduler *s)
	: Module(name, s) {
    }

    void build() {
	getSched()->registerCycleFn(
	    SchedEvent(this,
		       [this](){ cycle(); }, "cycle"));
    }

    void cycle() {
	std::cout << "cycle " << getCycle() << std::endl;
    }

    string getModuleName() const {
	return "ModuleA";
    }

    Port* getPort(const string&) const {
	return nullptr;
    }
};

int main() {
    auto *sched = new Scheduler(1000);
    auto *ma = new ModuleA("top", sched);
    ma->build();

    sched->advance(10);
}
