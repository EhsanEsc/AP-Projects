
#include "file_system.h"
using namespace std;

FileSystem::FileSystem()
{
  Dir* d = new Dir(0,0,"root");
  elements.push_back(d);
}

void FileSystem::add_file_to_dir(int parent_id, Element* el)
{
  if(find_by_id(parent_id) == NULL || find_by_id(parent_id)->get_type() != "Directory")
    throw BadParentId();
  
  Element* ee = find_by_id(parent_id);
  Dir* par = dynamic_cast<Dir*>(ee);
  par->add_element(el);
}

void FileSystem::add_directory(int id, std::string title, int parent_id)
{
  if(find_by_id(id) != NULL)
    throw IdAlreadyExists();

  Dir* d = new Dir(id,parent_id,title);
  add_file_to_dir(parent_id,d);
  elements.push_back(d);
}

void FileSystem::add_file(int id, std::string title, std::string content, int parent_id)
{
  if(find_by_id(id) != NULL)
    throw IdAlreadyExists();

  File* d = new File(id,parent_id,title,content);
  add_file_to_dir(parent_id,d);
  elements.push_back(d);
}
void FileSystem::add_link(int id, std::string title, int element_id, int parent_id)
{
  if(find_by_id(id) != NULL)
    throw IdAlreadyExists();
  if(find_by_id(element_id) == NULL || find_by_id(element_id)->get_type() == "Link")
    throw BadLinkedElement();

  Link* d = new Link(id,title,find_by_id(element_id),parent_id);
  add_file_to_dir(parent_id,d);
  elements.push_back(d);
}

void FileSystem::view(int id)
{
  Element* el = find_by_id(id);
  if(el == NULL)
    throw BadElementId();
  el->view();
}

Element* FileSystem::find_by_id(int id)
{
  for(auto u:elements)
    if(u->get_id() == id)
      return u;
  return NULL;
}
