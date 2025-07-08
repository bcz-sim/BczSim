
#include <csp/sim/Module.hh>
#include <soc/chi/Port.hh>

namespace soc::chi {

class Module : public csp::Module {
public:
    Module(csp::Module *parent, const string &name);
    CHIPort* getPortById(int id) const;
    CHIPort* getPortByName(string &name) const;
};

}
