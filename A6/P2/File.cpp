
#include "File.h"
using namespace std;

File::File(int _id, int pid, string tit, string _content)
: Element(_id,pid,tit)
{
  content = _content;
}

void File::view()
{
    cout << "Title: " << title << endl;
    cout << "Content: " << endl;
    cout << content << endl;
}

string File::get_type()
{
  return "File";
}
