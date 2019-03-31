
#ifndef THREAD_H
#define THREAD_H

#include<iostream>

class Process;
class Core;

class Thread{
  private:
    int id;
    int cnt_slices;
    Process* process_parent;
    Core* processor;

  public:
    Thread();
    ~Thread();
    Thread(int _id,int _cnt_slices,Process* _proccess_parent);

    void setProccessor(Core* cr);

    void show();
    void showTimeSlices();

    bool isFinished();

    void run();
};

#endif
