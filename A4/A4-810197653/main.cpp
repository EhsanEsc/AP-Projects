#include <iostream>
#include <vector>
#include "Thread.h"
#include "Process.h"
#include "Core.h"

using namespace std;

const string NEW_PROCESS = "add_process";
const string STATUS = "show_cores_stat";
const string FINISH = "finish_tasks";
const string NEW_CORE = "add_core";
const string RUN = "run_cores";
const int INF = 1000000000;
const int N = 10000;

void runAllCores(vector<Core> &cores) {
    for (Core &core : cores)
        core.runTimeslice();
}

bool isFinished(vector<Core> &cores) {
    bool ret = true;
    for (Core core : cores)
        ret &= core.isQueueEmpty();
    return ret;
}

Core* findFirstCoreWithSmallestQueue(vector<Core> &cores) {
    int minSize = INF;
    Core* ret = NULL;
    for (Core &core : cores) {
        if (core.sizeOfQueue() < minSize) {
            minSize = core.sizeOfQueue();
            ret = &core;
        }
    }
    return ret;
}

void runUntilFinish(vector<Core> &cores) {
    int timeSlice = 1;
    while (!isFinished(cores)) {
        cout << "Time Slice : " << timeSlice << endl;
        timeSlice ++;
        runAllCores(cores);
    }
}

void addNewCore(vector<Core> &cores) {
    cores.push_back(Core(cores.size() + 1, deque<Thread*>()));
    cout << "Core with core ID = " << cores.size() << " successfully added!" << endl;
}

void printAllStatuses(vector<Core> &cores) {
    for (Core core : cores)
        core.printStatus();
}

void handleNewProcess(vector<Core> &cores, vector<Process> &processes) {
    int numberOfThreads;
    cin >> numberOfThreads;
    Process::numberOfProcesses ++;
    processes.push_back(Process(Process::numberOfProcesses, numberOfThreads));

    for (int threadId = 1; threadId <= numberOfThreads; threadId++) {
        int numberOfTimeSlotsForThread;
        cin >> numberOfTimeSlotsForThread;
        processes.back().addThread(Thread(threadId, &processes.back(), numberOfTimeSlotsForThread));
        Core* core = findFirstCoreWithSmallestQueue(cores);
        core->addThread(processes.back().getLastThread());
    }
    cout << "Process with pid = " << Process::numberOfProcesses << " added!" << endl;
}

int main() {
    string command;
    vector<Core> cores;
    cores.reserve(N);
    vector<Process> processes;
    processes.reserve(N);

    while (cin >> command){
        if (command == NEW_CORE) {
            addNewCore(cores);
        }else if (command == STATUS) {
            printAllStatuses(cores);
        }else if(command == RUN) {
            runAllCores(cores);
        }else if(command == FINISH) {
            runUntilFinish(cores);
        }else if(command == NEW_PROCESS) {
            handleNewProcess(cores, processes);
        }
    }
}
