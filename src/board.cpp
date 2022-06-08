#include <board.hpp>

Board::Board() : width{800}, height{600}
{
    assert(width > 0);
    assert(height > 0);
}

Board::Board(int width_in, int height_in) : width{width_in}, height{height_in}
{
    assert(width > 0);
    assert(height > 0);
}
