#include "get_avg_of_vector.hpp"

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <stdexcept>

using namespace std;

TEST_CASE("normal test")
{
  vector<int>v1(8,100);
  CHECK(get_avg_of_vector(v1) == Approx(100));

  vector<int>v2{1,9,4,3,13250,39,679};
  CHECK(get_avg_of_vector(v2) == Approx(1997.857));

  vector<int>v3(4,16);
  CHECK(get_avg_of_vector(v3) == Approx(16));

  vector<int>v4{-4,5,-3,1,0,0,0,0,3,123,-1212,1211,-122,-2};
  CHECK(get_avg_of_vector(v4) == Approx(0));

  vector<int>v5{-12,-123,-554,-89,22};
  CHECK(get_avg_of_vector(v5) == Approx(-151.2));

  vector<int>v6{0};
  CHECK(get_avg_of_vector(v6) == Approx(0)) ;
}

TEST_CASE("invalid vector")
{
  vector<int>v1;

  CHECK_THROWS_AS(get_avg_of_vector(v1), std::length_error);
}
