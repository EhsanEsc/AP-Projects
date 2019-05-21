#include "Process.h"

#include <iostream>

#include "Thread.h"
#include "ThreadScheduler.h"

using namespace std;

Process::Process()
{
}

void Process::add_thread(Thread* new_thread)
{
    threads.push_back(new_thread);
    new_thread->set_thread_id(threads.size());
}

unsigned int Process::get_number_of_threads()
{
    return threads.size();
}

vector<Thread*> Process::get_threads()
{
    return threads;
}

unsigned int Process::get_process_id()
{
    return process_id;
}

void Process::set_process_id(unsigned int _process_id)
{
    process_id = _process_id;
}

void Process::print_process()
{
    constexpr uint8_t FIRST_INDEX = 0;

    for (unsigned int i = FIRST_INDEX; i < threads.size(); ++i)
        threads[i]->print_thread_stat();
    cout << endl;
}

