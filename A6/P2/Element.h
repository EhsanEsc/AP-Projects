
#ifndef ELEMENT_H
#define ELEMENT_H

#include <string>
#include <iostream>
#include "Errors.h"

class Element
{
public:
  Element(int _id, int pid,std::string _title);

  virtual void view() = 0;
  virtual std::string get_type() = 0;

  void print_title();
  int get_id();
  std::string get_title();
protected:
  std::string title;
  int id;
  int parent_id;
};

#endif
