#ifndef BOARD_HPP
#define BOARD_HPP

#include <assert.h>
#include <vector>
using std::vector;

#include <memory>
using std::shared_ptr;

class Board
{
private:
    int width, height;

public:
    Board(/* args */) = default;
    Board(int width_in, int height_in);
    ~Board();
};

#endif // BOARD_HPP