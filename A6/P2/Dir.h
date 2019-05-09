
#ifndef DIR_H
#define DIR_H

#include <string>
#include <vector>
#include "Element.h"

class Dir : public Element
{
public:
  Dir(int _id, int _pid, std::string _title);
  void add_element(Element* el);
  void view();
  std::string get_type();
private:
  bool check_exist(std::string tit);
  std::vector<Element*> elements;
};

#endif
