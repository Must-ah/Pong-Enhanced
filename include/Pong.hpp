#ifndef PONG_HPP
#define PONG_HPP

#include "board.hpp"
#include "Player.hpp"


class Pong
{
private:
    /* data */
    Player human_player;
    Player AI_player;
    Board board;
public:
    Pong(/* args */);
    ~Pong();
};



#endif // PONG_HPP