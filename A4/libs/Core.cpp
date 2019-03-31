
#include "Core.h"
#include "Thread.h"

using namespace std;

Core::Core(){ setAll(-1 , deque<Thread*>() , NULL); }
Core::~Core(){}
Core::Core(int _id){ setAll(_id , deque<Thread*>() , NULL); }

void Core::setAll(int _id,deque<Thread*>_que,Thread* _last_thread)
{
  id = _id;
  que = _que;
  last_thread = _last_thread;
}

void Core::showId()
{
  cout << "Core number : " << id << endl;
}

void Core::showAllThreads()
{
  for(Thread* thr:que)
  {
    thr->show();
    thr->showTimeSlices();
  }
}

void Core::showLastThread()
{
  last_thread->show();
}

bool Core::isFree()
{
  return que.empty() == true;
}

bool Core::isRun()
{
  return last_thread != NULL;
}

void Core::run()
{
  Thread* thr = que.front();
  que.pop_front();

  thr->run();
  last_thread = thr;

  if(thr->isFinished() == false)
    addThread(thr);
}

void Core::addThread(Thread* thr)
{
  que.push_back(thr);
}

void Core::freeStack()
{
  last_thread = NULL;
}
