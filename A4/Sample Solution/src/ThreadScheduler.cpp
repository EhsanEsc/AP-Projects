#include "ThreadScheduler.h"

#include <iostream>

#include "Core.h"
#include "Process.h"

using namespace std;

constexpr unsigned int FIRST_ID = 1;

ThreadScheduler* ThreadScheduler::instance;

ThreadScheduler::ThreadScheduler()
: next_process_id(FIRST_ID)
, next_core_id(FIRST_ID)
{
}

unsigned int ThreadScheduler::get_next_process_id()
{
    return next_process_id;
}

unsigned int ThreadScheduler::get_next_core_id()
{
    return next_core_id;
}

void ThreadScheduler::increment_next_process_id()
{
    next_process_id++;
}

void ThreadScheduler::increment_next_core_id()
{
    next_core_id++;
}

void ThreadScheduler::run_cores()
{
	for (Core* core: cores)
		core->run_thread();
}

void ThreadScheduler::show_cores_stat()
{
	for(Core* core: cores)
		core->print_core_stat();
}

void ThreadScheduler::add_core()
{
	Core* new_core = new Core(next_core_id);
	cores.push_back(new_core);
	increment_next_core_id();
	
	cout << "Core with core ID = " << new_core->get_core_id() <<
			" successfully added!" << endl;
}

void ThreadScheduler::finish_tasks()
{
	unsigned int time_slice = 1;
	while (is_unfinished_task_exist())
	{
		cout << "Time Slice : " << time_slice << endl;
		run_cores();
		time_slice++;
	}
}

void ThreadScheduler::add_process(Process* new_process)
{
	new_process->set_process_id(next_process_id);
	increment_next_process_id();

	for(Thread* thread : new_process->get_threads())
		get_pricewit_core_index()->add_to_queue(thread);

	processes.push_back(new_process);

	cout << "Process with pid = " << new_process->get_process_id() <<
			" added!" << endl;
}

Core* ThreadScheduler::get_pricewit_core_index()
{
	unsigned int min_index = 0;

	for (unsigned int i = 0; i < cores.size(); ++i)
		if (cores[i]->get_queue_size() < cores[min_index]->get_queue_size())
			min_index = i;

	return cores[min_index];
}

ThreadScheduler* ThreadScheduler::get_instance()
{
	if (instance == nullptr)
		instance = new ThreadScheduler();
	return instance;
}

bool ThreadScheduler::is_unfinished_task_exist()
{
	for (Core* core: cores)
		if (core->get_queue_size() > 0)
			return true;

	return false;
}
