
#include "Module.hh"

namespace csp {

void Module::setSchedAll(Scheduler *sched)
{
    sched_ = sched;
    auto modules = getSubModules();
    for (auto *mod: modules) {
        mod->setSchedAll(sched);
    }
}

StdVector<Module*> Module::getSubModules() const
{
    std::vector<Module*> modules;
    auto children = SimObj::getChildren();
    for (SimObj *obj: children) {
        Module *mod = dynamic_cast<Module>(obj);
        if (mod)
            modules.push_back(mod);
    }
    return modules;
}

Port* Module::getPort(const string& name) const
{
    auto children = SimObj::getChildren();
    for (SimObj *obj: children) {
        Port *p = dynamic_cast<Port>(obj);
        if (p->getName() == name)
	    return p;
    }
    return nullptr;
}

}
