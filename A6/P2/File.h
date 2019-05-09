
#ifndef FILE_H
#define FILE_H

#include<string>
#include "Element.h"

class File : public Element
{
public:
  File(int _id, int pid, std::string tit, std::string _content);
  void view();
  std::string get_type();
private:
  std::string content;
};

#endif
