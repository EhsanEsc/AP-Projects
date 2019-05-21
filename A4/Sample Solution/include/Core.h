#ifndef CORE_H_
#define CORE_H_

#include <vector>

class Thread;

class Core
{
public:
    Core(unsigned int _core_id);

    void add_to_queue(Thread* new_thread);
    unsigned int get_queue_size();
    unsigned int get_core_id();

    void print_core_stat();
    
    void run_thread();
    void run_first_thread();
    void amend_core_queue();

private:
    std::vector<Thread*> waiting_queue;
    unsigned int core_id;
};

#endif