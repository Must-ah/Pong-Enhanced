#ifndef PONG_HPP
#define PONG_HPP

#include <utility>
using std::make_pair;
using std::pair;


#include "board.hpp"
#include "Player.hpp"

class Pong
{
private:
    /* data */
    Board board;
    Player human_player;
    Player AI_player;
    pair<int, int> game_score{0, 0};

    /* methods */
    void init_new_game(int width_in, int height_in); // [X]
    void restart_game();                             // [X]
    void init_board(int width_in, int height_in);    // [X]
    void init_players();                             // [X]

public:
    Pong(/* args */);
    Pong(int width_in, int height_in);
    ~Pong(){};

    /* Methods */
    pair <int, int> get_board_dimensions();
    pair<int, int> get_game_score();
    void set_game_score(pair<int, int> new_game_score);
    void reset_game_score();
    Player get_human_player();
    Player get_AI_player();

};

#endif // PONG_HPP