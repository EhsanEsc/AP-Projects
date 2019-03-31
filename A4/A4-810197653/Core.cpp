#include "Core.h"
#include "Thread.h"
using namespace std;

Core::Core(int _id, deque<Thread*> _queue)
    : id(_id), queue(_queue) {}

bool Core::isQueueEmpty() {
    return queue.empty();
}

void Core::addThread(Thread* thread) {
    queue.push_back(thread);
}
int Core::sizeOfQueue() {
    return queue.size();
}

void Core::printId() {
    cout << "Core number : " << id << endl;
}

void Core::runTimeslice() {
    if (queue.empty())
        return;
    Thread* frontThread = queue.front();
    printRuntimesliceLogs(frontThread);
    frontThread->decreaseNumberOfTimeSlots();
    if (frontThread->getNumberOfTimeSlots() > 0)
        queue.push_back(frontThread);
    queue.pop_front();
}

void Core::printRuntimesliceLogs(Thread* thread) {
    this->printId();
    thread->printIdInformation();
}

void Core::printStatus() {
    this->printId();
    for (Thread* thread : queue){
        thread->printIdInformation();
        thread->printNumberOfTimeSlots();
    }
}
