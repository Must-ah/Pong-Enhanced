#include "../include/Player.hpp"

Player::Player(/* args */) : player_dimension(make_pair(100, 150)), player_position(make_pair(400, 300))
{
    assert_player();
}

Player::Player(int width, int height, int x, int y) : player_dimension(make_pair(width, height)), player_position(make_pair(x, y))
{
    assert_player();
}

void Player::assert_player()
{
    auto const &[width, height] = player_dimension;
    assert(width > 0 && height > 0);
    auto const &[x, y] = player_position;
    assert(x > 0 && y > 0);
}

pair<int, int> Player::get_player_dimension()
{
    return player_dimension;
}

pair<int, int> Player::get_player_position()
{
    return player_position;
}