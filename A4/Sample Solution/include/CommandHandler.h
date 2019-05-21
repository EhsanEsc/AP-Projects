#ifndef COMMAND_HANDLER_H_
#define COMMAND_HANDLER_H_

#include <string>
#include <vector>

class Process;

class CommandHandler
{
public:
    typedef std::vector<std::string> StringList;

    static CommandHandler* get_instance();
    Process* create_process(std::string input_line);
    StringList split_string(std::string input);

    void run();

private:    
    CommandHandler();
    static CommandHandler* instance;
};

#endif