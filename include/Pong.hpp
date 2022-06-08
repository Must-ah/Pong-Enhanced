#ifndef PONG_HPP
#define PONG_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "board.hpp"
#include "Player.hpp"

class Pong
{
private:
    /* data */
    Board board;
    Player human_player;
    Player AI_player;

    /* methods */
    void init_new_game(int width_in, int height_in); // [X]
    void restart_game();                             // [X]
    void init_board(int width_in, int height_in);    // [X]
    void init_players();                             // [X]

public:
    Pong(/* args */);
    Pong(int width_in, int height_in);
    pair <int, int> get_board_dimensions();
    ~Pong(){};
};

#endif // PONG_HPP