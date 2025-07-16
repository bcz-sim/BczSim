
// Bruce

namespace csp {

template <class T>
class RcPtr {
public:
    class Base {
        int16_t magic;
        int16_t flags;
        int32_t rcnt;
        friend class RcPtr;
    };
    RcPtr() : obj_(nullptr) {}
    RcPtr(T *obj) : obj_(obj)

private:
    T *obj_;
};

template <class T>
using RcBase = RcPtr<T>::Base;


}
