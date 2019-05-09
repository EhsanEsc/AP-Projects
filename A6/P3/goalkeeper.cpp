
#include "goalkeeper.h"
#include "striker.h"

GoalKeeper::GoalKeeper(int st,int dr,int ps,int def,std::string tn)
: Player(st,dr,ps,def,tn)
{}

Player* GoalKeeper::action()
{
  if(front_player == reciver)
    return reciver;
  Striker* st = dynamic_cast<Striker*>(front_player);
  if(fight(st))
  {
    tired();
    return reciver;
  }
  else
  {
    st->tired();
    return st;
  }
}

bool GoalKeeper::fight(Striker* st)
{
  return pass > (st->get_defend()/2);
}
