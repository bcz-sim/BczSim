
#include "Arguments.hh"

namespace csp {

static Arguments global_arguments;

const Arguments& Arguments::get(void)
{
    return global_arguments;
}

void Arguments::init(int argc, char *argv[])
{
    (void)argc;
    (void)argv;
}


}
