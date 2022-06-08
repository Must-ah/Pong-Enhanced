#ifndef BOARD_HPP
#define BOARD_HPP

#include <assert.h>
#include <vector>
using std::vector;

#include <memory>
using std::shared_ptr;

class Pieces;
class Players;
class Board
{
private:
    int width, height;
    vector<shared_ptr<Pieces>> pieces;
    vector<shared_ptr<Players>> players;

public:
    Board(/* args */) = default;
    Board(int width_in, int height_in);
    ~Board();
};

#endif // BOARD_HPP