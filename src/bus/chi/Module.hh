
#include <csp/sim/Module.hh>
#include <bus/chi/Port.hh>

namespace bus::chi {

class Module : public csp::Module {

    CHIPort* getPortById(int id) const;
    CHIPort* getPortByName(string &name) const;
};

}
