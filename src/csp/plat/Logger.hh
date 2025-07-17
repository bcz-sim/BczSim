// Bruce Zhong

#include <csp/base/types.hh>
#include <functional>

namespace csp {

enum LogLevel {
    LogVerbose, LogDebug, LogTrace, LogNote, LogWarn, LogError
};

class OutStream;
class Logger {
    OutStream *out_;
    int logger_id_;
    LogLevel pr_level_ = LogDebug;
    std::function<int(char*,int)> pfx_func_;
    std::function<bool(void)> pr_check_func_;

public:
    Logger(string ostm_name);

    // pfx_func(char *buf, int max)
    void setPrefixFunc(std::function<int(char*,int)> func) {
        pfx_func_ = func;
    }
    void setPrintCheckFunc(std::function<bool(void)> func) {
        pr_check_func_ = func;
    }
    void setLogLevel(LogLevel lvl) {
        pr_level_ = lvl;
    }

    int getLoggerId() const { return logger_id_; }

    bool shouldPrint(LogLevel logl) {
        if (logl < pr_level_) return false;
        if (pr_check_func_ && !pr_check_func_()) return false;
        return true;
    }

    template <typename... Args>
    void debug(Args... args)  { message(LogDebug, args...); }
    template <typename... Args>
    void vdebug(Args... args) { message(LogVerbose, args...); }

    template <typename... Args>
    void trace(Args... args) { message(LogTrace, args...); }
    template <typename... Args>
    void note(Args... args)  { message(LogNote, args...); }
    template <typename... Args>
    void warn(Args... args)  { message(LogWarn, args...); }
    template <typename... Args>
    void error(Args... args) { message(LogError, args...); }

private:
    template <typename... Args>
    void message(LogLevel logl, Args... args) {
        if (shouldPrint(logl))
            pr_msg(logl, args...);
    }

    void pr_msg(LogLevel logl, const char *fmt, ...)
        __attribute__((format(printf, 3, 4)));

public:
    static void initLoggers(void);
};

}
