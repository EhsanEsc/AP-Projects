#ifndef THREAD_H_
#define THREAD_H_

class Process;

class Thread
{
public:
    Thread(int _number_of_time_slots, Process* _process);

    void run_thread();
    Process* get_process();
    int get_number_of_time_slots();
    
    unsigned int get_thread_id();
    void set_thread_id(unsigned int _thread_id);

    void print_thread_stat();

private:
    int number_of_time_slots;
    unsigned int thread_id;
    Process* process;
};

#endif