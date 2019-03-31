

#include "Thread.h"
#include "Process.h"

using namespace std;

Thread::Thread(){}
Thread::~Thread(){}
Thread::Thread(int _id,int _cnt_slices,Process* _proccess_parent)
{
  id = _id;
  cnt_slices = _cnt_slices;
  process_parent = _proccess_parent;
}

void Thread::setProccessor(Core* cr)
{
  processor = cr;
}

void Thread::show()
{
  cout << "Process ID : " << process_parent->getId() << " - " ;
  cout << "Thread ID : " << id << endl;
}

void Thread::showTimeSlices()
{
  cout << "Number of time slots : " << cnt_slices << endl;
}

bool Thread::isFinished()
{
  return cnt_slices==0;
}

void Thread::run()
{
  cnt_slices--;
}
