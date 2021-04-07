

#ifndef UNTITLED3_BOARD_HPP
#define UNTITLED3_BOARD_HPP
#include <iostream>
#include "Direction.hpp"
using namespace std;
namespace ariel {

    class Board {

        char** m_board;
        size_t m_rows;
        size_t m_cols;
        pair<std::size_t,std::size_t> m_min_axis;
        pair<std::size_t,std::size_t> m_max_axis;
    public:

        Board():m_board(nullptr),m_rows(0),m_cols(0)
        {

        }




        void post(size_t,size_t,ariel::Direction, string);
        string read(size_t,size_t,ariel::Direction,size_t);
        void show();
        ~Board()
        {
            for (int i = 0; i <m_rows ; ++i) {
                delete m_board[i];
            }
            delete m_board;
        }

        void check_dimensions();
    };

}

#endif //UNTITLED3_BOARD_HPP
