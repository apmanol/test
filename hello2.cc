#include <typeinfo>
#include <boost/algorithm/string/predicate.hpp>
#include "catch.hpp"
#include <iostream>

TEST_CASE( "Test type deduction", "[decltorial]" ){
  auto a = 1 + 2;
  CHECK(boost::equals(typeid(a).name(),"i"));
}