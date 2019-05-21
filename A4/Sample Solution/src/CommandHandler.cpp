#include "CommandHandler.h"

#include <iostream>
#include <iterator>
#include <sstream>

#include "ThreadScheduler.h"
#include "Thread.h"
#include "Process.h"

using namespace std;

CommandHandler* CommandHandler::instance;

CommandHandler::CommandHandler()
{
}

CommandHandler* CommandHandler::get_instance()
{
	if (instance == nullptr)
		instance = new CommandHandler();
	return instance;
}

void CommandHandler::run()
{
    constexpr char ADD_PROCESS[] = "add_process";
    constexpr char ADD_CORE[] = "add_core";
    constexpr char SHOW_CORES_STAT[] = "show_cores_stat";
    constexpr char RUN_CORES[] = "run_cores";
    constexpr char FINISH_TASKS[] = "finish_tasks";
    constexpr uint8_t COMMAND_TYPE_INDEX = 0;

    ThreadScheduler* thread_scheduler = ThreadScheduler::get_instance();

	string input;
    
	while (getline(cin, input))
	{
        const string command_type = split_string(input)[COMMAND_TYPE_INDEX];

		if (command_type == ADD_PROCESS)
			thread_scheduler->add_process(create_process(input));

		else if (command_type == ADD_CORE)
			thread_scheduler->add_core();

		else if (command_type == SHOW_CORES_STAT)
			thread_scheduler->show_cores_stat();

		else if (command_type == RUN_CORES)
			thread_scheduler->run_cores();
        
        else if (command_type == FINISH_TASKS)
			thread_scheduler->finish_tasks();
	}
}

CommandHandler::StringList CommandHandler::split_string(string input)
{
    stringstream input_string_stream(input);
    return vector<string>(istream_iterator<string>(input_string_stream),
            istream_iterator<string>());
}

Process* CommandHandler::create_process(string input_line)
{
    constexpr uint8_t FIRST_THREAD_ARGUMENT_INDEX = 2;

    const CommandHandler::StringList string_list = split_string(input_line);
    Process* new_process = new Process();

    for (unsigned int i = FIRST_THREAD_ARGUMENT_INDEX; i < string_list.size(); i++)
        new_process->add_thread(new Thread(stoi(string_list[i]), new_process));
    
    return new_process;
}
