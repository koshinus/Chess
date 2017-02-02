#include <iostream>
#include"model.hpp"

using namespace std;

int main()
{
    chess_board new_chess_board = chess_board();
    int turn = 0;
    char old_col, new_col;
    int old_row, new_row;
    string state;
    while(true)
    {
        cout << "Write \"exit\" to finish, or something else to continue" << endl;
        if(turn == 0) cout << "Now white turn\n";
            else "Now black turn\n";
        cin >> state;
        if(state != "exit")
        {
            new_chess_board.show();
            cout << "Write old and new coordinates for some figure" << std::endl;
            cin >> old_col >> old_row >> new_col >> new_row;
            old_row--;
            new_row--;
            colors turn_color = new_chess_board.get_chess_by_place(
                    intP(old_row, get_val_by_litera(old_col))).get_color();
            if (turn_color == colors::white && turn == 0)
            {
                if(new_chess_board.chess_move(intP(old_row, get_val_by_litera(old_col)),
                                           intP(new_row, get_val_by_litera(new_col))))
                    turn++;
            }
            else if (turn_color == colors::black && turn == 1)
            {
                if(new_chess_board.chess_move(intP(old_row, get_val_by_litera(old_col)),
                                           intP(new_row, get_val_by_litera(new_col))))
                    turn--;
            }
            else cout << "It's not your turn!" << endl;
        }
        else break;
    }
    //cout << "Hello, World!" << endl;
    return 0;
}