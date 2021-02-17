#include "Person.hpp"
#include <stdexcept>
#include <string>

#define CATCH_CONFIG_MAIN
#include "../catch.hpp"

TEST_CASE("`get_fullname` test") {
  Person person("Edsger", "Dijkstra");
  REQUIRE(person.get_fullname() == "Edsger Dijkstra");
}

TEST_CASE("constructor empty firstname test") {
  REQUIRE_THROWS_AS(Person("", "Dijkstra"), std::invalid_argument);
}
