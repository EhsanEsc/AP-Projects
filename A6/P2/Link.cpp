
#include "Link.h"
using namespace std;

Link::Link(int _id, string _title, Element* dd, int pid)
: Element(_id,pid,_title)
{
  ref = dd;
}

void Link::view()
{
  cout << "Title: " << title << endl;
  ref->view();
}

string Link::get_type()
{
  return "Link";
}
