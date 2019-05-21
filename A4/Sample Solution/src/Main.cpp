#include "CommandHandler.h"

int main()
{   
    CommandHandler* command_handler =
            CommandHandler::get_instance();

    command_handler->run();
    return 0;
}