
#include "Platform.hh"
#include "Arguments.hh"
#include "Logger.hh"

namespace csp {

void Platform::init(int argc, char *argv[])
{
    Arguments::init(argc, argv);
    Logger::initLoggers();
}

}
