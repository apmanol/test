#include <typeinfo>
#include <type_traits>
#include "catch.hpp"
#include <iostream>

template <class T, class U>
auto add(T t, U u)
    -> decltype(t + u) // the return type is the type of operator+(T, U)
{
  return t + u;
}

template <typename T> struct DT {};

TEST_CASE("Test type deduction", "[decltorial]") {
  auto a = 1 + 2;
  bool same = std::is_same<decltype(a), int>::value;
  REQUIRE(same);

  const auto &b = add(1, 1.2);
  same = std::is_same<decltype(b), const double &>::value;
  REQUIRE(same);

  const auto c = {1, 2};
  // DT<decltype(c)> DTtype;
  // DTtype = 0;
  // different stuff in clang and gcc
#if defined(_clang_)
  same = std::is_same<decltype(c), const std::initializer_list<int>>::value;
#elif defined(_GNUC_)
  same =
      std::is_same<decltype(c), const std::initializer_list<const int>>::value;
#endif
  REQUIRE(same);

  auto k = []() {};
  auto f = [](int a, int b) -> int { return a * b; };

  decltype(f) g = f; // the type of a lambda function is unique and unnamed
  auto i = f(2, 2);
  auto j = g(3, 3);
  CHECK(i == 4);
  CHECK(j == 9);

  const auto& n = 5;
  same = std::is_same<decltype(n), const int &>::value;
  REQUIRE(same);
  const auto* np = &n;
  same = std::is_same<decltype(np), const int *>::value;
  REQUIRE(same);

  auto&& nr = n;
  same = std::is_same<decltype(nr), const int &>::value;
  REQUIRE(same);
}
