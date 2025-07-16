
#pragma once

#include <csp/base/types.hh>
#include <csp/sim/SimObj.hh>

#include <functional>

namespace csp {

class Port  : public SimObj {
    Port  *target_;
public:
    Port(SimObj *parent, const string &name)
        : SimObj(parent, name) { }

    void connect(Port *t) { target_ = t; }
};

#if 0
// T : Payload type
template <class T>
class Port  : public SimObj {
    Port<T>  *target_;
    std::function<void(T&)> receiver_;
public:
    Port(SimObj *parent, const string &name)
        : SimObj(parent, name) { }

    void setRecevier(std::function<void(T&)> rec) {
        receiver_ = rec;
    }

    virtual bool receive(T &pld) const {
        if (receiver_) return receiver_(pld);
        else           return false;
    }
    bool send(T &pld) const {
        return target_->receive(pld);
    }
};
#endif

}
