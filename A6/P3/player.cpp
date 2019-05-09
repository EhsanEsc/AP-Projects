
#include "player.h"
using namespace std;

Player::Player(int st, int dr, int ps ,int def, string tn)
{
  if(st<0 || st>100 || dr<0 || dr>100 || ps<0 || ps>100 || def<0 || def>100)
    throw "Values are not in range 0-100";
  stamina = st;
  dribble = dr;
  defend = def;
  pass = ps;
  team_name = tn;
  front_player = back_player = NULL;
}
string Player::get_team()
{
  return team_name;
}
int Player::get_defend()
{
  return defend;
}
void Player::tired()
{
  stamina-=10;
  dribble-=10;
  defend-=10;
  pass-=10;
  stamina = max(0,stamina);
  dribble = max(0,dribble);
  defend = max(0,defend);
  pass = max(0,pass);
}
bool Player::score_goal()
{
  return front_player == NULL;
}

void Player::set_back(Player* po) { back_player = po; }
void Player::set_front(Player* po) { front_player = po; }
void Player::set_reciver(Player* po) { reciver = po; }


Player* Player::get_back() { return back_player; }
