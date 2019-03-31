#include "Thread.h"
#include "Process.h"
using namespace std;

Thread::Thread(int _id, Process* _process, int _numberOfTimeSlots)
    : id(_id), process(_process), numberOfTimeSlots(_numberOfTimeSlots) {}

int Thread::getNumberOfTimeSlots() {
    return numberOfTimeSlots;
}

Process* Thread::getProcess() {
    return process;
}

int Thread::getId() {
    return id;
}

void Thread::decreaseNumberOfTimeSlots() {
    numberOfTimeSlots --;
}

void Thread::printIdInformation() {
    cout << "Process ID : " << this->getProcess()->getId() << " - Thread ID : " << id << endl;
}

void Thread::printNumberOfTimeSlots() {
    cout << "Number of time slots : " << numberOfTimeSlots << endl;
}
