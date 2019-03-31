
#ifndef CORE_H
#define CORE_H

#include<iostream>
#include<deque>

class Thread;

class Core{
  private:
    int id;
    Thread* last_thread;
    std::deque<Thread*>que;

  public:
    Core();
    ~Core();
    Core(int _id);

    int getId() { return id; }
    int getQueSize() { return que.size(); }

    void setAll(int _id,std::deque<Thread*>_que,Thread* _last_thread);

    void showId();
    void showAllThreads();
    void showLastThread();

    bool isFree();
    bool isRun();

    void run();
    void addThread(Thread* thr);
    void freeStack();
};

#endif
