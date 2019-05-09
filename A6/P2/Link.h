
#ifndef LINK_H
#define LINK_H

#include <string>
#include "Element.h"

class Link : public Element
{
public:
  Link(int _id, std::string _title, Element* dd, int pid);
  void view();
  std::string get_type();
private:
  Element* ref;
};

#endif
