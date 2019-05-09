
#include "striker.h"
#include "defender.h"
#include "goalkeeper.h"
using namespace std;

Striker::Striker(int st,int dr,int ps,int def,std::string tn)
: Player(st,dr,ps,def,tn)
{}
Player* Striker::action()
{
  Striker* st = dynamic_cast<Striker*>(front_player);
  GoalKeeper* gk = dynamic_cast<GoalKeeper*>(front_player);
  Defender* df = dynamic_cast<Defender*>(front_player);
  if(fight(st) || fight(gk) || fight(df))
  {
    drible();
    tired();
    return this;
  }
  else
  {
    front_player->tired();
    return front_player;
  }
}

bool Striker::fight(Striker* st)
{
  if(st == NULL) return false;
  return dribble > (st->get_defend()+5);
}

bool Striker::fight(GoalKeeper* gk)
{
  if(gk == NULL) return false;
  return dribble > (4*gk->get_defend()/3);
}

bool Striker::fight(Defender* df)
{
  if(df == NULL) return false;
  return (dribble > df->get_defend());
}

void Striker::drible()
{
  Player* en = front_player;

  set_front(en->get_back());
  en->set_front(back_player);

  set_back(en);
  en->set_back(this);
}
