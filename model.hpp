//
// Created by vadim on 05.12.15.
//

#ifndef TEST_CHESS_MODEL_HPP
#define TEST_CHESS_MODEL_HPP

#include "create_figure.hpp"
#include<map>
#include<vector>
#include<string>

using ChessBoardLine = std::vector<std::pair<colors, chess>>;
using ChessBoard = std::vector<ChessBoardLine>;
using intP = std::pair<int,int>;

char get_litera_by_val(int val)
{
    return char(val+96);
}

int get_val_by_litera(char lit)
{
    return lit-65;
}

class chess_board
{
private:
    //Qmap<int, Qmap<char, Qpair<colors, chess>>> q_chess_board1;
    ChessBoard q_chess_board;
public:
    chess_board()
    {
        q_chess_board = ChessBoard(8, ChessBoardLine(8, std::pair<colors, chess>(colors::white,chess())));
        for(int row = 0; row < 8; row++)
        {
            for(int column = 0; column < 8; column++)
            {
                chess some_chess;
                switch (row)
                {
                    case 7:
                        some_chess = get_figure_by_row_and_column(row, column);
                        break;
                    case 6:
                        some_chess = chess(figures::pawn, colors::black);
                        break;
                    case 1:
                        some_chess = chess(figures::pawn, colors::white);
                        break;
                    case 0:
                        some_chess = get_figure_by_row_and_column(row, column);
                        break;
                    default:
                        some_chess = chess(figures::none, colors::white);
                        break;
                }
                colors cage_color =
                        ((row+column)%2 == 1)?
                        colors::white:
                        colors::black;
                q_chess_board[row][column].first  = cage_color;
                q_chess_board[row][column].second = some_chess;
            }
        }
    }

    std::string show_figure(figures some_figure)
    {
        switch (some_figure)
        {
            case figures::pawn:
            {
                return "pawn  ";
            }
            case figures::knight:
            {
                return "knight";
            }
            case figures::bishop:
            {
                return "bishop";
            }
            case figures::rook:
            {
                return "rook  ";
            }
            case figures::queen:
            {
                return "queen ";
            }
            case figures::king:
            {
                return "king  ";
            }
            default:
            {
                return "      ";
            }
        }
    }

    void show()
    {
        /*     A         B
         * --------------------
         *|    WC    |   BC    |
         *|  white   |  black  |
         *|  bishop  |  queen  |
         * --------------------
         * */
        std::string whitespace = std::string(9, ' ');
        std::cout << std::string(5, ' ') << 'A' << whitespace << 'B' <<
                     whitespace << 'C' << whitespace << 'D' <<
                     whitespace << 'E' << whitespace << 'F' <<
                     whitespace << 'G' << whitespace << 'H' << std::endl;
        std::string str = std::string(81, '-');
        for(size_t i = 0; i < q_chess_board.size(); i++)
        {
            std::cout << str << 7-i+1 << std::endl;
            for(int k = 0; k < 3; k++)
                for(size_t j = 0; j < q_chess_board[0].size(); j++)
                {
                    std::pair<colors, chess> chess_board_cage = q_chess_board[7-i][j];
                    switch (k)
                    {
                        case 0:
                        {
                            if(chess_board_cage.first == colors::white)
                                std::cout << "|    WC   ";
                            else std::cout << "|    BC   ";
                            break;
                        }
                        case 1:
                        {
                            if(chess_board_cage.second.get_figure() == figures::none)
                                std::cout << "|         ";
                            else if(chess_board_cage.second.get_color() == colors::white)
                                std::cout << "|  white  ";
                            else std::cout << "|  black  ";
                            break;
                        }
                        case 2:
                        {
                            std::cout << "|  "
                            << show_figure(chess_board_cage.second.get_figure()) << " ";
                            break;
                        }
                        default:
                            break;
                    }
                    if(j == 7) std::cout << "|" << std::endl;
                }
        }
        std::cout << str << std::endl;
    }

    bool is_empty_cage(intP cage)
    {
        try
        {
            return
                    q_chess_board.at(cage.first).at(cage.second).second.get_figure() == figures::none;
        } catch (std::out_of_range) { return false; }
    }

    bool chess_move(intP from, intP to)
    {
        if(valid(from, to))
        {
            if(get_chess_by_place(from).get_figure() == figures::pawn &&
                        (to.first == 7 || to.first == 0))
            while(true)
            {
                std::cout << "Choose figure to change pawn: queen, rook, bishop or knight";
                std::string str;
                std::cin >> str;
                if(str == "queen")
                {
                    q_chess_board[to.first][to.second].second.set_figure
                            (figures::queen, q_chess_board[from.first][from.second].second.get_color());
                    q_chess_board[from.first][from.second].second.set_figure(figures::none, colors::white);
                    return true;
                }
                else if(str == "rook")
                {
                    q_chess_board[to.first][to.second].second.set_figure
                            (figures::rook, q_chess_board[from.first][from.second].second.get_color());
                    q_chess_board[from.first][from.second].second.set_figure(figures::none, colors::white);
                    return true;
                }
                else if(str == "bishop")
                {
                    q_chess_board[to.first][to.second].second.set_figure
                            (figures::bishop, q_chess_board[from.first][from.second].second.get_color());
                    q_chess_board[from.first][from.second].second.set_figure(figures::none, colors::white);
                    return true;
                }
                else if(str == "knight")
                {
                    q_chess_board[to.first][to.second].second.set_figure
                            (figures::knight, q_chess_board[from.first][from.second].second.get_color());
                    q_chess_board[from.first][from.second].second.set_figure(figures::none, colors::white);
                    return true;
                }
                else std::cout << "Please write figure correctly!" << std::endl;
            }
            else
            {
                q_chess_board[to.first][to.second].second.set_figure
                        (q_chess_board[from.first][from.second].second.get_figure(),
                         q_chess_board[from.first][from.second].second.get_color());
                q_chess_board[from.first][from.second].second.set_figure(figures::none, colors::white);
                return true;
            }
        }
        else
        {
            std::cout << "This move is impossible! Write correct variant." << std::endl;
            return false;
        }
    }

    bool valid(intP from, intP to)
    {
        switch(q_chess_board[from.first][from.second].second.get_figure())
        {
            case figures::pawn:
                return validate_pawn_moves(from, to);
            case figures::knight:
                return validate_knight_moves(from, to);
            case figures::bishop:
                return validate_bishop_moves(from, to);
            case figures::rook:
                return validate_rook_moves(from, to);
            case figures::queen:
                return validate_queen_moves(from, to);
            case figures::king:
                return validate_king_moves(from, to);
            default:
                return false;
        }
    }

    chess get_chess_by_place(intP place)
    {
        return q_chess_board.at(place.first).at(place.second).second;
    }

    bool validate_pawn_moves(intP from, intP to)
    {
        chess pawn = get_chess_by_place(from);
        try
        {
            chess some_chess = get_chess_by_place(to);
        } catch (std::out_of_range) { return false; }
        if(pawn.get_color() == colors::white)
        {
            if (from.first == 1) //pawn on start may walk trough 2 squares forward
            {
                if (to.first == from.first + 2 && to.second == from.second &&
                    is_empty_cage(intP(from.first + 1, from.second)) && is_empty_cage(to))
                    return true;
                else if (to.first == from.first + 1 && to.second == from.second &&
                     is_empty_cage(to))
                return true;
                else if ((
                                 (to.first == from.first + 1 && to.second == from.second + 1) ||
                                 (to.first == from.first + 1 && to.second == from.second - 1)  )
                         && !is_empty_cage(to) && get_chess_by_place(to).get_color() == colors::black
                        )
                    return true;
            }
            else if ((
                        (to.first == from.first + 1 && to.second == from.second + 1) ||
                        (to.first == from.first + 1 && to.second == from.second - 1)  )
                        && !is_empty_cage(to) && get_chess_by_place(to).get_color() == colors::black
                    )
                    return true;
            else
                return to.first == from.first + 1 && to.second == from.second && is_empty_cage(to);
        }
        else
        {
            if(from.first == 6) //pawn on start may walk trough 2 squares forward
            {
                if (to.first == from.first - 2 && to.second == from.second &&
                    is_empty_cage(intP(from.first - 1, from.second)) && is_empty_cage(to))
                    return true;
                else if (to.first == from.first - 1 && to.second == from.second &&
                         is_empty_cage(to))
                    return true;
                else if ((
                                 (to.first == from.first - 1 && to.second == from.second + 1) ||
                                 (to.first == from.first - 1 && to.second == from.second - 1)  )
                         && !is_empty_cage(to) && get_chess_by_place(to).get_color()  == colors::white
                        )
                    return true;
            }
            else if ((
                        (to.first == from.first - 1 && to.second == from.second + 1) ||
                        (to.first == from.first - 1 && to.second == from.second - 1)  )
                        && !is_empty_cage(to) && get_chess_by_place(to).get_color()  == colors::white
                    )
                    return true;
            else
                return to.first == from.first - 1 && to.second == from.second &&
                     is_empty_cage(to);
        }
    }

    bool check_for_knight(chess knight, intP to)
    {
        if(is_empty_cage(to))
            return true;
        else return get_chess_by_place(to).get_color() != knight.get_color();
    }

    bool validate_knight_moves(intP from, intP to)
    {
        chess knight = get_chess_by_place(from);
        try
        {
            chess some_chess = get_chess_by_place(to);
        } catch (std::out_of_range) { return false; }
        return check_for_knight(knight, to) &&
          ((from.first - to.first ==  1 && from.second - to.second ==  2) ||
           (from.first - to.first ==  1 && from.second - to.second == -2) ||
           (from.first - to.first == -1 && from.second - to.second ==  2) ||
           (from.first - to.first == -1 && from.second - to.second == -2) ||
           (from.first - to.first ==  2 && from.second - to.second ==  1) ||
           (from.first - to.first ==  2 && from.second - to.second == -1) ||
           (from.first - to.first == -2 && from.second - to.second ==  1) ||
           (from.first - to.first == -2 && from.second - to.second == -1));
    }

    bool validate_check_step(chess some_chess, intP from, intP to,
                             int step_by_row, int step_by_column)
    {
        try
        {
            int i = from.first;
            int j = from.second;
            while(abs(i - to.first) > 0 || abs(j - to.second) > 0)
            {
                i+=step_by_row;
                j+=step_by_column;
                if(!is_empty_cage(intP(i, j)))
                    return false;
            }
            if(!is_empty_cage(intP(i, j)))
            {
                return some_chess.get_color() != get_chess_by_place(intP(i, j)).get_color();
            }
            return true;
        }catch (std::out_of_range) { return false; }
    }

    bool validate_bishop_moves(intP from, intP to)
    {
        if(from.first < to.first && from.second < to.second)
            return validate_check_step(get_chess_by_place(from), from, to, 1, 1);
        else if(from.first < to.first && from.second > to.second)
            return validate_check_step(get_chess_by_place(from), from, to, 1, -1);
        else if(from.first > to.first && from.second < to.second)
            return validate_check_step(get_chess_by_place(from), from, to, -1, 1);
        else if(from.first > to.first && from.second > to.second)
            return validate_check_step(get_chess_by_place(from), from, to, -1, -1);
        else return false;
    }

    bool validate_rook_moves(intP from, intP to)
    {
        if(from.first == to.first)
        {
            if (from.second < to.second)
                return validate_check_step(get_chess_by_place(from), from, to, 0, 1);
            else return validate_check_step(get_chess_by_place(from), from, to, 0, -1);
        }
        else if(from.second == to.second)
        {
            if (from.first < to.first)
                return validate_check_step(get_chess_by_place(from), from, to, 1, 0);
            else return validate_check_step(get_chess_by_place(from), from, to, -1, 0);
        }
        else return false;
    }

    bool validate_queen_moves(intP from, intP to)
    {
        return validate_bishop_moves(from,to) || validate_rook_moves(from,to);
    }

    bool validate_king_moves(intP from, intP to)
    {
        try
        {
            chess some_chess = get_chess_by_place(to);
            chess king = get_chess_by_place(from);
            return abs(from.first - to.first) <= 1 &&
                   abs(from.second - to.second) <= 1 &&
                   (king.get_color() != some_chess.get_color());
        }catch (std::out_of_range) {return false;}
    }
};


#endif //TEST_CHESS_MODEL_HPP