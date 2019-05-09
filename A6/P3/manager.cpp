
#include "manager.h"
using namespace std;

Manager::Manager()
{
  for(int i=0;i<6;i++)
    players[i] = NULL;
  ball_owner = NULL;
}

void Manager::add_player(int pos, Player* po)
{
  if(players[pos] != NULL)
    throw "Add Same Player Twice!";
  players[pos] = po;
}

void Manager::start_game()
{
  prepare_game();
  while(is_finish_game() == false)
  {
    play_round();
  }
}

void Manager::prepare_game()
{
  for(int i=0;i<6;i++)
    if(players[i] == NULL)
      throw "Not All Players Added!";
  ball_owner = players[2];
  for(int i=0;i<=2;i++)
    players[i]->set_front(players[i+1]);
  for(int i=5;i>=3;i--)
    players[i]->set_front(players[i-1]);

  for(int i=1;i<=2;i++)
    players[i]->set_back(players[i-1]);
  for(int i=4;i>=3;i--)
    players[i]->set_back(players[i+1]);

  for(int i=0;i<=1;i++)
    players[i]->set_reciver(players[i+1]);
  for(int i=5;i>=4;i--)
    players[i]->set_reciver(players[i-1]);
}

void Manager::play_round()
{
  cnt_rounds++;
  ball_owner = ball_owner->action();
}

bool Manager::is_finish_game()
{
  if(cnt_rounds >=5)
    return true;
  if(ball_owner->score_goal())
    return true;
  return false;
}

void Manager::print_result()
{
  if(ball_owner->score_goal())
  {
    cout << "result: team " << ball_owner->get_team() << " wins" << endl;
  }
  else
  {
    cout << "result: draw!" << endl;
  }

}
