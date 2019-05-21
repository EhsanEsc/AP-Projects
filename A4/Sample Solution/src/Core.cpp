#include "Core.h"

#include <iostream>

#include "Thread.h"

using namespace std;

Core::Core(unsigned int _core_id)
: core_id(_core_id)
{
}

void Core::add_to_queue(Thread* new_thread)
{
    waiting_queue.push_back(new_thread);
}

void Core::print_core_stat()
{
    cout << "Core number : " << core_id << endl;

    for (Thread* thread: waiting_queue)
        thread->print_thread_stat();
}

unsigned int Core::get_queue_size()
{
    return waiting_queue.size();
}

unsigned int Core::get_core_id()
{
    return core_id;
}

void Core::run_first_thread()
{
    constexpr uint8_t FIRST = 0;
    
    Thread* first_thread = waiting_queue[FIRST];
    cout << "Core number : " << core_id << endl;
    first_thread->run_thread();
}

void Core::amend_core_queue()
{
    constexpr uint8_t FIRST = 0;
    constexpr uint8_t EMPTY = 0;

    Thread* first_thread = waiting_queue[FIRST];
    
    if (first_thread->get_number_of_time_slots() != EMPTY)
        waiting_queue.push_back(first_thread);

    waiting_queue.erase(waiting_queue.begin());
}

void Core::run_thread()
{
    constexpr uint8_t EMPTY = 0;

    if (waiting_queue.size() == EMPTY)
        return;

    run_first_thread();
    amend_core_queue();
}