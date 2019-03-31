
#ifndef PROCESS_H
#define PROCESS_H

#include<iostream>
#include<vector>

#include "Thread.h"

class Process{
  private:
    int id;
    std::vector<Thread> que;

  public:
    Process();
    ~Process();
    Process(int _id);

    int getId() { return id; }
    std::vector<Thread>& getQue(){ return que; }

    void addThread(Thread thr);
};

#endif
