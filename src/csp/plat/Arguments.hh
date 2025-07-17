// Bruce Zhong

#include <csp/base/types.hh>

namespace csp {

// For command-line arguments;
struct Arguments {
    string log_file;  // --log-file FILE

    static const Arguments& get(void);
    static void init(int argc, char *argv[]);
};

}
