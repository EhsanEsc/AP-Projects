#ifndef __PERSON_H__
#define __PERSON_H__

#include <string>

class Person {
private:
  std::string firstname;
  std::string lastname;

public:
  Person(std::string firstname, std::string lastname);
  std::string get_firstname() const;
  std::string get_lastname() const;
  std::string get_fullname() const;
};

#endif
