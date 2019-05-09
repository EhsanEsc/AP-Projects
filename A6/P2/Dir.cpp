
#include "Dir.h"
using namespace std;

Dir::Dir(int _id, int pid, string _title)
: Element(_id,pid,_title)
{

}

void Dir::add_element(Element* el)
{
  if(check_exist(el->get_title()))
    throw BadTitle();
  elements.push_back(el);
}

void Dir::view()
{
  cout << "Title: " << title << endl;
  for(auto u:elements)
    u->print_title();
}

string Dir::get_type()
{
  return "Directory";
}

bool Dir::check_exist(string tit)
{
  for(auto u:elements)
    if(u->get_title() == tit)
      return true;
  return false;
}
