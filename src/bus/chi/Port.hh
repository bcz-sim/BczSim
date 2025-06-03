
#include <bus/chi/Request.hh>
#include <bus/chi/Flit.hh>

namespace bus::chi {

using ReqPort = csp::Port<RcPtr<Request>>;
using CHIPort = csp::Port<uptr<Flit>>;

}
