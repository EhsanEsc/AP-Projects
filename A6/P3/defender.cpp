
#include"defender.h"
#include"striker.h"
using namespace std;
Defender::Defender(int st,int dr,int ps,int def,std::string tn)
: Player(st,dr,ps,def,tn)
{}
Player* Defender::action()
{
  if(reciver == front_player)
    return reciver;
  Striker* st = dynamic_cast<Striker*>(front_player);
  Defender* df = dynamic_cast<Defender*>(front_player);
  if(fight(st) || fight(df))
  {
    tired();
    return reciver;
  }
  else
  {
    front_player->tired();
    return front_player;
  }
}

bool Defender::fight(Striker* st)
{
  if(st == NULL) return false;
  return pass > (st->get_defend()+15);
}

bool Defender::fight(Defender* df)
{
  if(df == NULL) return false;
  return pass > (df->get_defend()+10);
}
