#pragma once

#include <cassert>
#include <string>
#include <vector>

class A {
 public:
  std::string m_data;
  int m_data2;
  std::string *m_data3 = new std::string("test data");

  A() = default;
  A(const char *str) : m_data(str) {}

  ~A() { delete m_data3; }

  A(const A &rhs)
      : m_data(rhs.m_data),
        m_data2(rhs.m_data2),
        m_data3(new std::string(*rhs.m_data3)) {}

  A(A &&rhs) : m_data(std::move(rhs.m_data)), m_data2(rhs.m_data2) {
    m_data3 = rhs.m_data3;
    rhs.m_data3 = nullptr;
  }

  A &operator=(const A &rhs) = default;

  A &operator=(A &&rhs) {
    m_data = std::move(rhs.m_data);

    m_data3 = rhs.m_data3;
    rhs.m_data3 = nullptr;

    return *this;
  }
};

class B {
 public:
  std::string m_data;
  int m_data2;

  A m_data4;

  B(const B &rhs)
      : m_data(rhs.m_data)  // <<<<
        ,
        m_data4(rhs.m_data4) {}
};

std::vector<A> aaa;

void example_function() {
  A a1("aaaaa aaaaaa aaaaa ...");

  A a2 = a1;
  A a2(a1);

  A a3(std::move(a1));

  a2 = a3;
  a2 = std::move(a3);

  A aBig("aaaaa aaaaaa aaaaa ...");
  aBig.m_data += "more and more...";
  aaa.push_back(std::move(aBig));  // <<<<
}