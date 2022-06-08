#include "../include/board.hpp"

Board::Board()
{
    Board{800, 600};
    assert(width > 0);
    assert(height > 0);
}

Board::Board(int width_in, int height_in) : width{width_in}, height{height_in}
{
    assert(width > 0);
    assert(height > 0);
}

pair<int, int> Board::get_dimensions() const
{
    return make_pair(width, height);
}