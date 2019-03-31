#ifndef THREAD_H
#define THREAD_H

#include <iostream>

class Process;

class Thread {
public:
    Thread(int _id, Process* _process, int _numberOfTimeSlots);
    int getNumberOfTimeSlots();
    Process* getProcess();
    int getId();
    void printIdInformation();
    void printNumberOfTimeSlots();
    void decreaseNumberOfTimeSlots();
private:
    int id;
    int numberOfTimeSlots;
    Process* process;
};

#endif
