
#include <csp/sim/Module.hh>
#include <csp/plat/Platform.hh>

using namespace csp;

class ModuleA : public Module {
    uptr<SchedHelper> schh_;
    uptr<Logger> logger_;
public:
    ModuleA(const string &name, Scheduler *s)
        : Module(name, s) {
        schh_ = std::make_unique<SchedHelper>(getSched(), this, "callback",
                                              -1, nullptr, SchedPreTick);
        logger_ = createLogger("");
    }

    void build() {
        getSched()->registerCycleFn(
            SchedEvent(this,
                       [this](){ cycle(); }, "cycle"));
    }

    void cycle() {
        logger_->debug("%s do cycle", getName().c_str());
        if (getCycle() == 2) {
            logger_->debug("schedule callback, +3");
            schh_->callback(3, [this](){
                logger_->debug("callback");
            });
        }
    }

    string getModuleName() const {
        return "ModuleA";
    }

    Port* getPort(const string&) const {
        return nullptr;
    }
};

int main(int argc, char *argv[]) {
    Platform::init(argc, argv);

    auto *sched = new Scheduler(2000);
    auto *ma = new ModuleA("top", sched);
    ma->build();

    sched->advance(10);
}
