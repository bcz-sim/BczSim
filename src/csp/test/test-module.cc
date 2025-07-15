
#include <csp/sim/Module.hh>

#include <iostream>

using namespace csp;

class ModuleA : public Module {
public:
    ModuleA(Module *parent, const string &name)
	: Module(parent, name) {
	;
    }

    void build() {
	getSched()->registerCycleFn({this, [this]{ cycle(); }, "cycle"});
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
    auto *ma = new ModuleA(nullptr, "module_a");
    ma->setSchedAll(sched);

    sched->advance(100);
}
