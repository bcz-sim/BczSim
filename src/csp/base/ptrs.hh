
#include <memory>

namespace csp {

template <typename T>
using uptr = std::unique_ptr<T>;

template <typename T>
using sptr = std::shared_ptr<T>;

template <typename T>
using pptr = T*;

template <typename T>
using rcptr = Refcnt<T>;

}
