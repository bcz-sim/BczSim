
#include "Scheduler.hh"

namespace csp {

void Scheduler::setFrequency(long freq_mhz)
{
    freq_mhz_ = freq_mhz;
    ticks_per_cycle_ =  1000000 / freq_mhz;
}

}
