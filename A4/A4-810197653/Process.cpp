#include "Process.h"
using namespace std;

Process::Process(int _id, int numberOfThreads)
    : id(_id) {
    listOfThreads.reserve(numberOfThreads);
}

void Process::addThread(Thread thread) {
    listOfThreads.push_back(thread);
}

int Process::getId() {
    return id;
}

Thread* Process::getLastThread() {
    return &listOfThreads.back();
}

static int numberOfProcesses;
int Process::numberOfProcesses = 0;
