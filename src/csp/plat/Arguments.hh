// Bruce Zhong

#include <csp/base/types.hh>

namespace csp {

// For command-line arguments;
struct Arguments {

    // global level log control
    string log_level;  // --log-level [vdebug,debug,trace,note]
    string log_file;   // --log-file FILE

    static const Arguments& get(void);
    static void init(int argc, char *argv[]);
};

}
