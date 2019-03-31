#ifndef PROCESS_H
#define PROCESS_H

#include <iostream>
#include <vector>
#include "Thread.h"

class Process {
public:
    Process(int _id, int numberOfThreads);
    void addThread(Thread thread);
    int getId();
    Thread* getLastThread();
    static int numberOfProcesses;
private:
    int id;
    std::vector<Thread> listOfThreads;
};

#endif
