#ifndef PROCESS_H_
#define PROCESS_H_

#include <vector>

class Thread;

class Process
{
public:
    Process();

    void add_thread(Thread* new_thread);

    unsigned int get_number_of_threads();
    std::vector<Thread*> get_threads();
    
    unsigned int get_process_id();
    void set_process_id(unsigned int _process_id);
    
    void print_process();

private:
    std::vector<Thread*> threads;
    unsigned int process_id;
};

#endif