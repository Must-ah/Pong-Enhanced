#include "../include/Pong.hpp"

Pong::Pong(/* args */)
{
    init_new_game(800, 600);
}

Pong::Pong(int width_in, int height_in)
{
    init_new_game(width_in, height_in);
}

void Pong::init_new_game(int width_in, int height_in)
{
    init_board(width_in, height_in);
    init_players();
}


void Pong::init_board(int width_in, int height_in)
{
    /* code */
    board = Board {width_in, height_in};
    const auto &[width, height] = board.get_dimensions();
    assert(width > 0 && height > 0);
}

void Pong::init_players()
{
    /* code */
    const auto &[width, height] = board.get_dimensions();
    int player_width = 12;
    int player_height = height / 4;
    int player_x = 32;
    int player_y = (height / 2) - (player_height / 2);
    human_player = Player{
        player_width,
        player_height,
        player_x,
        player_y};
    player_x = width - player_width - 32;
    AI_player = Player{player_width,
              player_height,
              player_x,
              player_y};
}

void Pong::restart_game()
{
    /* code */
    const auto &[width, height] = board.get_dimensions();
    init_new_game(width, height);
}


pair<int, int> Pong::get_board_dimensions()
{
    /* code */
    return board.get_dimensions();
}