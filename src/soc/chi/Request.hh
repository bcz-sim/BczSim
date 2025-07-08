
namespace soc::chi {

enum ReqType {
    Req_None,
};

enum SnpType {
    Snp_None,
}

class Request : public csp::RefcntBase {
    ReqType req_type = Req_None;
    SnpType snp_type = Snp_None;
};

using RequestPtr = RcPtr<Request>;

}
