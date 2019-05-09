
#include "Element.h"
using namespace std;

Element::Element(int _id, int pid,std::string _title)
{
  id = _id;
  parent_id = pid;
  title = _title;
}
void Element::print_title()
{
  cout << "Title: " << title << ", ";
  cout << "Type: " << get_type() << endl;
}
int Element::get_id()
{
  return id;
}

std::string Element::get_title()
{
  return title;
}
