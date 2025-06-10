
#include <any>
#include <string>
#include <vector>
#include <map>

// use cds in https://gist.github.com/xzhong86/87aafbd1f8188b677f97f211800e02ff

// a simple implementation for common structured data, base on c++17 (std::any)
namespace csp::cds {

using Bool    = bool;
using Integer = long long int;
using Double  = double; // or use Float as name?
using String  = std::string;
using Value   = std::any;

class Any;
using Array   = std::vector<Any>;
using Table   = std::map<String, Any>; // only use string as key

class Any : public std::any {
public:
    using std::any::any;

    template <typename T>
    T as() const { return std::any_cast<T>(*this); }

    // as table when use string index, as array when use integer index
    Any operator[](const String &key) { return as<Table>()[key]; }
    Any operator[](size_t index)      { return as<Array>()[index]; }

    bool isBool()    const { return this->type() == typeid(Bool); }
    bool isInteger() const { return this->type() == typeid(Integer); }
    bool isDouble()  const { return this->type() == typeid(Double); }
    bool isString()  const { return this->type() == typeid(String); }
    bool isArray()   const { return this->type() == typeid(Array); }
    bool isTable()   const { return this->type() == typeid(Table); }

    Bool    to_b() const { return as<Bool>(); }
    Integer to_i() const { return as<Integer>(); }
    Double  to_f() const { return as<Double>(); }
    String  to_s() const { return as<String>(); }
};

Integer operator "" _I(unsigned long long int v)   { return Integer(v); }
Double  operator "" _F(unsigned long long int v)   { return Double(v); }
Double  operator "" _F(long double v) { return Double(v); }
String  operator "" _S(const char *s, size_t l) { return String(s, l); }

Value getByPath(const Table&, const String &);
}

