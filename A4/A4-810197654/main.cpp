// In The Name Of God

#include<iostream>
#include<deque>
#include<vector>

#include "libs/Core.h"
#include "libs/Thread.h"
#include "libs/Process.h"

#define WRONG_INPUT "Input is wrong!"

#define ADD_CORE_COMMAND "add_core"
#define ADD_PROCESS_COMMAND "add_process"
#define RUN_COMMAND "run_cores"
#define SHOW_STATS_COMMAND "show_cores_stat"
#define FINISH_COMMAND "finish_tasks"

const int MAX_THREAD = 100022;
const int MAX_CORES = 100022;
const int MAX_PROCESS = 100022;

using namespace std;

void raiseError(string message)
{
  cout << message << endl;
}

void addCoreMessage(int new_id)
{
  cout << "Core with core ID = " << new_id << " successfully added!" << endl;
}

int addCore(vector<Core>& cores)
{
  int new_id = cores.size() + 1;
  Core new_core(new_id);

  cores.push_back(new_core) ;

  return new_id;
}

int findMinThreads(vector<Core>& cores)
{
  int min_threads = MAX_THREAD;
  for(Core& cr:cores)
    min_threads = min(min_threads , cr.getQueSize());
  return min_threads;
}

Core* findWorklessCore(vector<Core>& cores)
{
  int min_threads = findMinThreads(cores);
  for(Core& cr:cores)
    if(min_threads == cr.getQueSize())
      return &cr;
}

void assignAllThreads(Process& pr , vector<Core>& cores)
{
  for(Thread& thr:pr.getQue())
  {
    Core* cr = findWorklessCore(cores);
    cr->addThread(&thr);
    thr.setProccessor(cr);
  }
}

Process& getProcessById(vector<Process>& processes , int id)
{
  return processes[id-1];
}

void addProcessMessage(Process& pr)
{
    cout << "Process with pid = " << pr.getId() << " added!" << endl;
}

void addThreads(Process& new_process)
{
  int thr_cnt;
  int thr_time_slices;

  cin>>thr_cnt;
  for(int id=1 ; id<=thr_cnt ; id++)
  {
    cin >> thr_time_slices ;
    Thread thr(id , thr_time_slices , &new_process) ;

    new_process.addThread(thr);
  }
}

int addProcess(vector<Core>& cores , vector<Process>& processes)
{
  int new_id = processes.size() + 1;
  Process new_process(new_id) ;
  processes.push_back(new_process);

  return new_id;
}

void showCoresStats(vector<Core>& cores)
{
  for(Core& cr:cores)
  {
    cr.showId();
    cr.showAllThreads();
  }
}

void showLastActions(vector<Core>& cores)
{
  for(Core& cr:cores)
  {
    if(cr.isRun() == false)
      continue;

    cr.showId();
    cr.showLastThread();
  }
}

void runCores(vector<Core>& cores)
{
  for(Core& cr:cores)
  {
    cr.freeStack();
    if(cr.isFree())
      continue;
    cr.run();
  }
}

bool isFinishAllActions(vector<Core>& cores)
{
  for(Core& cr:cores)
    if(cr.isFree() == false)
      return false;
  return true;
}

void finishCores(vector<Core>& cores)
{
  int time_slices_cnt=0;
  while(isFinishAllActions(cores) == false)
  {
    time_slices_cnt++;
    cout << "Time Slice : " << time_slices_cnt << endl;

    runCores(cores);
    showLastActions(cores);
  }
}

void calcRequests(vector<Core>& cores , vector<Process>& processes)
{
    string command ;
    while(cin>>command)
    {
    	if(command == ADD_CORE_COMMAND)
      {
        int new_core_id = addCore(cores);
        addCoreMessage(new_core_id);
      }
      else if(command == ADD_PROCESS_COMMAND)
      {
        int new_process_id = addProcess(cores,processes);
        Process& new_process = getProcessById(processes , new_process_id);
        addThreads(new_process);
        assignAllThreads(new_process,cores);
        addProcessMessage(new_process);
      }
      else if(command == SHOW_STATS_COMMAND)
      {
        showCoresStats(cores);
      }
      else if(command == RUN_COMMAND)
      {
        runCores(cores);
        showLastActions(cores);
      }
      else if(command == FINISH_COMMAND)
      {
        finishCores(cores);
      }
      else
      {
        raiseError(WRONG_INPUT);
      }
    }
}

int main()
{
  vector<Core> cores;
  vector<Process> processes;

  cores.reserve(MAX_CORES);
  processes.reserve(MAX_PROCESS);

  calcRequests(cores , processes);

  return 0;
}
