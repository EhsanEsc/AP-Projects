#include "Person.hpp"
#include <stdexcept>
#include <string>

Person::Person(std::string firstname, std::string lastname)
    : firstname(firstname), lastname(lastname) {
  if (firstname == "")
    throw std::invalid_argument("Firstname is required.");
}

std::string Person::get_firstname() const { return firstname; }

std::string Person::get_lastname() const { return lastname; }

/**/
std::string Person::get_fullname() const { return firstname + lastname; }
/**/

/*
std::string Person::get_fullname() const { return firstname + " " + lastname; }
*/
