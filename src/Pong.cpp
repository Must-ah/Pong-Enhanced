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
    board = Board{width_in, height_in};
    const auto &[width, height] = board.get_dimensions();
    assert(width > 0 && height > 0);
}
void Pong::center_players()
{
    const auto &[width, height] = board.get_dimensions();
    int player_width = 12;
    int player_height = height / 4;
    int player_x = 32;
    int player_y = (height / 2) - (player_height / 2);
    human_player = Player{
        player_width,
        player_height,
        player_x,
        player_y,
        game_speed};
    player_x = width - player_width - 32;
    AI_player = Player{player_width,
                       player_height,
                       player_x,
                       player_y,
                       game_speed};
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
        player_y,
        game_speed};
    player_x = width - player_width - 32;
    AI_player = Player{player_width,
                       player_height,
                       player_x,
                       player_y,
                       game_speed};
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

Player &Pong::get_AI_player()
{
    return AI_player;
}

Player &Pong::get_human_player()
{
    return human_player;
}
pair<int, int> &Pong::get_game_score()
{
    return game_score;
}

void Pong::set_game_score(pair<int, int> new_game_score)
{
    // const auto &[human_score, ai_score] = new_game_score;
    int human_score = new_game_score.first;
    int ai_score = new_game_score.second;
    game_score.first = human_score;
    game_score.second = ai_score;
}
void Pong::reset_game_score()
{
    game_score = make_pair<int, int>(0, 0);
}

void Pong::init_ball()
{
    const auto &[board_width, board_height] = board.get_dimensions();
    ball = Ball{16, 16, board_width / 2, board_height / 2, game_speed};
}
Ball &Pong::get_ball() { return ball; }

void Pong::reset_game()
{
    const auto &[board_width, board_height] = board.get_dimensions();
    ball = Ball{16, 16, board_width / 2, board_height / 2, game_speed};
    center_players();
}

int Pong::get_speed() { return game_speed; }
Board &Pong::get_board()
{
    return board;
}
void Pong::serve()
{
    reset_game();
    // human_player.
}