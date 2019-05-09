
#include "file_system_interface.h"
using namespace std;

void FileSystemInterface::add_directory(int id, std::string title, int parent_id)
{
  try {
    system.add_directory(id,title,parent_id);
  } catch(exception &e) {
    cerr << e.what() << endl;
  }
}

void FileSystemInterface::add_file(int id, std::string title, std::string content, int parent_id)
{
  try {
    system.add_file(id,title,content,parent_id);
  } catch(exception &e) {
    cerr << e.what() << endl;
  }
}

void FileSystemInterface::add_link(int id, std::string title, int element_id, int parent_id)
{
  try {
    system.add_link(id,title,element_id,parent_id);
  } catch(exception &e) {
    cerr << e.what() << endl;
  }
}

void FileSystemInterface::view(int id)
{
  try {
    system.view(id);
  } catch(exception &e) {
    cerr << e.what() << endl;
  }
}
