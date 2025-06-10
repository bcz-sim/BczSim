
#include <base/cds.hh>

#include <iostream>

int main() {
  using namespace cds;
  Table tab;
  tab["aaa"] = 111_I;
  tab["bbb"] = Table{ {"aa", 11_I }, {"bb", "22"_S }, { "cc", 3.3_F } };

  Array arr = { 11_I, 22_F, 33_I, 44_F, "ee"_S };
  arr.push_back("str");
  tab["arr"] = arr;

  std::cout << "tab[bbb] is table: " << tab["bbb"].isTable() << std::endl;
  std::cout << "tab[aaa].type.name: " << tab["aaa"].type().name() << std::endl;
  std::cout << "tab[aaa] is Integer: " << tab["aaa"].isInteger() << std::endl;
  std::cout << "tab[aaa] value: " << tab["aaa"].to_i() << std::endl;

  std::cout << "tab[bbb][bb] type name: " << tab["bbb"]["bb"].type().name() << std::endl;
  std::cout << "tab[bbb][bb] is string: " << tab["bbb"]["bb"].isString() << std::endl;

  std::cout << "tab[bbb][cc] type name: " << tab["bbb"]["cc"].type().name() << std::endl;
  std::cout << "tab[bbb][cc] value: " << tab["bbb"]["cc"].to_f() << std::endl;

  std::cout << "tab[arr][1] type name: " << tab["arr"][1].type().name() << std::endl;
  std::cout << "tab[arr][1] value: " << tab["arr"][1].to_f() << std::endl;

  tab["bool"] = true;
  std::cout << "tab[bool] type name: " << tab["bool"].type().name() << std::endl;
  std::cout << "tab[bool] value: " << tab["bool"].to_b() << std::endl;
}
