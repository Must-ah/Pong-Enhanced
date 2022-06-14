#include "../include/Ball.hpp"

Ball::Ball() : width{16}, height{16}, x{0}, y{0}, speed{22}
{
    ball_dimension = make_pair(width, height);
    ball_position = make_pair(x, y);
}

Ball::Ball(int width, int height, int x, int y, int speed) : width{width}, height{height}, x{x}, y{y}, speed{speed}
{
}
pair<int, int> Ball::get_ball_dimension() { return ball_dimension; }

pair<int, int> Ball::get_ball_position() { return ball_position; }

int Ball::get_ball_speed() { return speed; }

void Ball::set_update_ball_position(pair<int, int> updated_position)
{
    const auto &[new_x, new_y] = updated_position;
    ball_position.first = new_x;
    ball_position.second = new_y;
}
void Ball::update_ball_direction(int new_direction)
{
    direction = new_direction;
}
int Ball::get_ball_direction() { return direction; }

Ball::~Ball() {}