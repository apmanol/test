#include <iostream>
#include <thread>
#include <vector>
#include <algorithm>

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

TEST_CASE("Threads are spawned", "[threadorial]") {
  // REQUIRE( Factorial(1) == 1 );
  // REQUIRE( Factorial(2) == 2 );
  // REQUIRE( Factorial(3) == 6 );
  // REQUIRE( Factorial(10) == 3628800 );
  std::vector<std::thread> threads;
  for (auto i = 0; i < 10; i++) {
    std::cout << "starting threads" << std::endl;
    threads.push_back(std::thread(
        [i]() { // std::cout << "starting thread" << i << std::endl;
        }));
  }

  std::for_each(threads.begin(), threads.end(),
                [](std::thread &t) { t.join(); });

  auto k = new char[100];
}
