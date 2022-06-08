#ifndef BOARD_HPP
#define BOARD_HPP

#include <assert.h>

#include<utility>
using std::make_pair;
using std::pair;

class Board
{
private:
    int width, height;

public:
    Board(/* args */) ;
    Board(int width_in, int height_in);    
    ~Board(){};

    /* methods */
    pair<int, int> get_dimensions() const;
};

#endif // BOARD_HPP