#include "game_manager.h"

using namespace std;

int main()
{
	game_manager game = game_manager();
	game.add_team_A_goalkeeper(100, 10, 20, 65);
	game.add_team_A_defender(100, 20, 60, 80);
	game.add_team_A_striker(100, 70, 50, 30);
	game.add_team_B_goalkeeper(100, 50, 40, 50);
	game.add_team_B_defender(100, 85, 20, 90);
	game.add_team_B_striker(100, 50, 20, 10);
	game.play();
	game.get_result();
}
