
#pragma once

#include <csp/sim/SimObj.hh>

namespace csp {

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

    virtual bool receive(Payload &pld) const {
	if (receiver_) return receiver_(pld);
	else           return false;
    }
    bool send(Payload &pld) const {
	return target_->receive(pld);
    }
};

}
