#include <iostream>

class cstr {
 public:
  cstr();
  explicit cstr(std::string str);
  ~cstr();

  void setValue(std::string str);
  std::string getValue();

 private:
  std::string _str;
};