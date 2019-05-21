#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define EMPTY '#'
#define FULL 'o'
#define SUCCESS_MESSAGE "Insane!"
#define FAILURE_MESSAGE "Bad map configuration!"
#define SIDE_PADDING_EXTRA 2
#define SIDES_COUNT 2
#define JUMP_LEN 2
#define MOVES_COUNT 4
#define SURVIVAL_LIMIT 1

enum direction{
    LEFT = 'L',
    RIGHT = 'R',
    UP = 'U',
    DOWN = 'D'
};

struct Move{
    int row;
    int column;
    direction dir;
};

Move make_move(int, int, direction);
bool is_solvable(vector<string>&, vector<Move>&);

int main(){
    int height, width;
    vector <string> board;
    vector <Move> result;
    cin >> height >> width;

    string padding(width + SIDE_PADDING_EXTRA * SIDES_COUNT, '-');
    board.push_back(padding);
    board.push_back(padding);
    for(int i = 0; i < height; i++){
        string current;
        cin >> current;

        current = "--" + current + "--";
        board.push_back(current);
    }
    board.push_back(padding);
    board.push_back(padding);
    if(is_solvable(board, result)){
        cout << SUCCESS_MESSAGE <<endl;
        for(int i = 0; i < result.size(); i++){
            cout << result[i].row - 1 << " " << result[i].column - 1 << " " << char(result[i].dir) << endl;
        }
    } else{
        cout << FAILURE_MESSAGE << endl;
    }
    return 0;
}

bool is_solvable(vector<string>& board, vector<Move>& result){
    int peg_count = 0;

    const Move moves[] = {
        make_move(1, 0, DOWN),
        make_move(-1, 0, UP),
        make_move(0, 1, RIGHT),
        make_move(0, -1, LEFT)
    };
    
    for(int i = 0; i < board.size(); i++){
        for(int j = 0; j < board[i].size(); j++){
            if(board[i][j] != FULL){
                continue;
            }
            peg_count++;
            for(int m = 0; m < MOVES_COUNT; m++){
                if(!(board[i + moves[m].row][j + moves[m].column] == FULL &&
                     board[i + JUMP_LEN * moves[m].row][j + JUMP_LEN * moves[m].column] == EMPTY)){
                    continue;
                }
                board[i][j] = EMPTY;
                board[i + moves[m].row][j + moves[m].column] = EMPTY;
                board[i + JUMP_LEN * moves[m].row][j + JUMP_LEN * moves[m].column] = FULL;
                result.push_back(make_move(i, j, moves[m].dir));
                bool solved = is_solvable(board, result);
                
                board[i][j] = FULL;
                board[i + moves[m].row][j + moves[m].column] = FULL;
                board[i + JUMP_LEN * moves[m].row][j + JUMP_LEN * moves[m].column] = EMPTY;
                if(solved){
                    return true;
                }
                result.pop_back();
            }
        }
    }
    
    return peg_count == SURVIVAL_LIMIT;
}

Move make_move(int row, int column, direction dir){
    Move result;
    result.row = row;
    result.column = column;
    result.dir = dir;

    return result;
}
