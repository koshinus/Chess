//
// Created by vadim on 05.12.15.
//

#ifndef TEST_CHESS_CHESS_CLASS_HPP
#define TEST_CHESS_CHESS_CLASS_HPP

enum class figures {none, pawn, bishop, knight, rook, queen, king};

enum class colors {black, white};

class chess
{
private:
    figures figure;
    colors color;
public:
    chess(): figure(figures::none),color(colors::white){};
    chess(figures fig, colors col): figure(fig), color(col){}
    figures get_figure()
    {
        return figure;
    }
    colors get_color()
    {
        return color;
    }
    void set_figure(figures fig, colors col)
    {
        figure = fig;
        color  = col;
    }
};

#endif //TEST_CHESS_CHESS_CLASS_HPP
