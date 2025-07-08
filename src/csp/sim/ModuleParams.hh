
#include <csp/base/cds.hh>

namespace csp {

class ModuleParams {
public:
    virtual void setValues(cds::Table &tab) = 0;
};

}
