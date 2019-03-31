
#include "Process.h"

using namespace std;

Process::Process(){}
Process::~Process(){}
Process::Process(int _id){ id = _id; }

void Process::addThread(Thread thr)
{
  que.push_back(thr);
}
