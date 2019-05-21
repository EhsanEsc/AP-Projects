#include "Thread.h"

#include <iostream>

#include "Process.h"

using namespace std;

Thread::Thread(int _number_of_time_slots, Process* _process)
: number_of_time_slots(_number_of_time_slots)
, process(_process)
{
}

void Thread::print_thread_stat()
{
    cout << "Process ID : " << process->get_process_id() <<
            " - Thread ID : " << thread_id << endl <<
            "Number of time slots : " << number_of_time_slots << endl;
}

void Thread::run_thread()
{
    cout << "Process ID : " << process->get_process_id() <<
            " - Thread ID : " << thread_id << endl;

    number_of_time_slots--;
}

int Thread::get_number_of_time_slots()
{
    return number_of_time_slots;
}

unsigned int Thread::get_thread_id()
{
    return thread_id;
}

void Thread::set_thread_id(unsigned int _thread_id)
{
    thread_id = _thread_id;
}

Process* Thread::get_process()
{
    return process;
}