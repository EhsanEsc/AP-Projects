
#ifndef FILE_SYSTEM_H
#define FILE_SYSTEM_H

#include<string>
#include<vector>
#include<iostream>
#include "Errors.h"
#include "Dir.h"
#include "File.h"
#include "Link.h"

class FileSystem
{
public:
  FileSystem();
  void add_directory(int id, std::string title, int parent_id);
  void add_file(int id, std::string title, std::string content, int parent_id);
  void add_link(int id, std::string title, int element_id, int parent_id);

  void view(int id);
private:
  Element* find_by_id(int id);
  void add_file_to_dir(int id, Element* el);
  std::vector<Element*> elements;
};


#endif
