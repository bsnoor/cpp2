

#include "Board.hpp"
using namespace std;
void ariel::Board::post(size_t row, size_t col, ariel::Direction dir, string info) {
    if (this->m_board== nullptr)
    {
        size_t constant=20;
        m_rows=row+constant;
        m_cols=col+constant;

        this->m_board= new char*[m_rows];
        for (size_t i = 0; i <m_rows ; ++i) {
            m_board[i]= new char[m_cols];
        }
        for (size_t i = 0; i <m_rows ; ++i) {
            for (size_t j = 0; j <m_cols ; ++j) {
                m_board[i][j]='_';
            }
        }

    }
    if(dir==Direction::Horizontal)
    {
        m_max_axis.second+=info.size();
        /*
         * TODO : then the string is placed horizontally same row but incrementing cols
         */
        for (size_t i = 0; i <info.size() ; ++i) {
            m_board[row][col+i]=info[i];
        }
    }
    else
    {
    /*
     * TODO: meaning vertically we maintain the col and increment the rows
     */
        m_max_axis.first+=info.size();
        for (size_t i = 0; i <info.size() ; ++i) {
            m_board[row+i][col]=info[i];
        }



    }
}

string ariel::Board::read(size_t row, size_t col, ariel::Direction dir, size_t length) {
    string ans("");
    pair<size_t,size_t> index(row,col);
    if (dir== Direction::Horizontal)
    {
        for (size_t i = 0; i < length; ++i) {
            ans+=m_board[row][col+i];
        }
    }
    else
    {
        for (size_t i = 0; i < length; ++i) {
            ans+=m_board[row+i][col];
        }
    }
    return ans;
}

void ariel::Board::show() {
    check_dimensions();
//    cout<<this->m_min_axis.first;
//    cout<<endl<<this->m_min_axis.second<<endl;
    for (size_t i = m_min_axis.first-1; i <=m_max_axis.first+1 ; ++i) {

        cout<<i<<" :";
        for (size_t j = m_min_axis.second-1; j <=m_max_axis.second+1; ++j) {
            cout<<m_board[i][j];
        }
        cout<<endl;
    }
}

void ariel::Board::check_dimensions() {
/*
 *  TODO : traverse through the rows to find the minimum row , and so for cols , applies for min and max
 */
bool flag1= false;
    for (size_t i = 0; i <m_rows ; ++i) {
        for (size_t j = 0; j < m_cols &&!flag1; ++j) {
            if(m_board[i][j]!='_')
            {
                this->m_min_axis.first=i;
                flag1= true;
            }


        }
    }
flag1=false;
    for (size_t i = 0; i <m_cols ; ++i) {
        for (size_t j = 0; j < m_rows &&!flag1; ++j) {
            if(m_board[j][i]!='_'){
                this->m_min_axis.second=i;
                flag1=true;
                }
        }
    }

    for (size_t i = 0; i <m_rows ; ++i) {
        for (size_t j = 0; j < m_cols; ++j) {
            if(m_board[i][j]!='_')
            {
                this->m_max_axis.first=i;

            }


        }
    }

    for (size_t i = 0; i <m_cols ; ++i) {
        for (size_t j = 0; j < m_rows; ++j) {
            if(m_board[j][i]!='_'){
                this->m_max_axis.second=i;

            }
        }
    }
}

