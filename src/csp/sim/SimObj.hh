
#pragma once

#include <string>
#include <vector>

namespace csp {

class SimObj {
    SimObj *parent_;
    std::string name_;
    std::vector<SimObj*> children_;
    void addChild(SimObj *obj) { children_.push_back(obj); }
public:
    SimObj(SimObj *parent, const std::string &name)
	: parent_(parent), name_(name) {
	if (parent_)
	    parent_->addChild(this);
    }
    virtual ~SimObj() { }

    SimObj*   getParent() const { return parent_; }
    std::string getName() const { return name_; }

    // return a copy of children vector
    std::vector<SimObj*> getChildren() const { return children_; }
};

}
