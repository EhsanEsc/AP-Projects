#ifndef THREAD_SCHEDULER_H_
#define THREAD_SCHEDULER_H_

#include <memory>
#include <vector>

class Process;
class Core;

class ThreadScheduler
{    
public:
    static ThreadScheduler* get_instance();

    void add_process(Process* process);
    void add_core();
    void show_cores_stat();
    bool has_unfinished_task();
    void run_cores();
    void finish_tasks();

    unsigned int get_next_process_id();
    unsigned int get_next_core_id();

private:
	ThreadScheduler();

    void increment_next_process_id();
    void increment_next_core_id();
    Core* get_pricewit_core_index();
    bool is_unfinished_task_exist();
    
	static ThreadScheduler* instance;

    unsigned int next_process_id;
    unsigned int next_core_id;
    
    std::vector<Process*> processes;
    std::vector<Core*> cores;
};

#endif