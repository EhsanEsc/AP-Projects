#include "file_system_interface.h"

int main()
{
    FileSystemInterface interface = FileSystemInterface();
    interface.view(0);

    interface.add_directory(1, "etc", 0);
    interface.view(2);    

    return 0;
}
