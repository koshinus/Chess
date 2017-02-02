//
// Created by vadim on 05.12.15.
//

#ifndef TEST_CHESS_CREATE_FIGURE_HPP
#define TEST_CHESS_CREATE_FIGURE_HPP
#include "chess_class.hpp"

chess get_figure_by_row_and_column(int row, int column)
{
    switch(column)
    {
        case 0:
        {
            return (row == 7)?
                   chess(figures::rook, colors::black):
                   chess(figures::rook, colors::white);
        }
        case 1:
        {
            return (row == 7)?
                   chess(figures::knight, colors::black):
                   chess(figures::knight, colors::white);
        }
        case 2:
        {
            return (row == 7)?
                   chess(figures::bishop, colors::black):
                   chess(figures::bishop, colors::white);
        }
        case 3:
        {
            return (row == 7)?
                   chess(figures::queen, colors::black):
                   chess(figures::queen, colors::white);
        }
        case 4:
        {
            return (row == 7)?
                   chess(figures::king, colors::black):
                   chess(figures::king, colors::white);
        }
        case 5:
        {
            return (row == 7)?
                   chess(figures::bishop, colors::black):
                   chess(figures::bishop, colors::white);
        }
        case 6:
        {
            return (row == 7)?
                   chess(figures::knight, colors::black):
                   chess(figures::knight, colors::white);
        }
        case 7:
        {
            return (row == 7)?
                   chess(figures::rook, colors::black):
                   chess(figures::rook, colors::white);
        }
        default:break;
    }
}

#endif //TEST_CHESS_CREATE_FIGURE_HPP
