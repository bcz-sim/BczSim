
#include "Logger.hh"
#include <iostream>
#include <cstdio>
#include <cstdarg>

namespace csp {

static int global_logger_id = 100;

void Logger::initLoggers(void)
{
    ;
}

Logger::Logger(string out_name)
{
    logger_id_ = global_logger_id ++;
}

void Logger::pr_msg(LogLevel l, const char *fmt, ...)
{
    va_list args;
    constexpr int max = 256;
    char buf[max];
    int  len = 0;

    va_start(args, fmt);

    if (!shouldPrint(l)) return;
    if (pfx_func_)
        len += pfx_func_(buf, max / 2);

    len += std::vsnprintf(buf + len, max - len - 1, fmt, args);

    if (buf[len-1] != '\n')
        buf[len++] = '\n';

    //out_->write(buf, len);
    std::cout.write(buf, len);
    va_end(args);
}

}
