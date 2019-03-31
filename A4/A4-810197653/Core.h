#ifndef CORE_H
#define CORE_H

#include <iostream>
#include <deque>

class Thread;

class Core {
public:
    Core(int _id, std::deque<Thread*> _queue);
    void runTimeslice();
    void printRuntimesliceLogs(Thread* thread);
    void printStatus();
    void printId();
    bool isQueueEmpty();
    void addThread(Thread* thread);
    int sizeOfQueue();
private:
    int id;
    std::deque<Thread*> queue;
};

#endif
