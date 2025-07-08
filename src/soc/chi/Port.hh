
#include <soc/chi/Request.hh>
#include <soc/chi/Flit.hh>

namespace soc::chi {

using ReqPort = csp::Port<RcPtr<Request>>;
using CHIPort = csp::Port<uptr<Flit>>;

}
