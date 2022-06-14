#ifndef BALL_HPP
#define BALL_

#include <utility>
using std::make_pair;
using std::pair;

class Ball
{
private:
    /* data */
    int width;
    int height;
    int x;
    int y;
    pair<int, int> ball_dimension;
    pair<int, int> ball_position;
    int speed;
    int direction = -1;

public:
    Ball(/* args */);
    Ball(int width, int height, int x, int y, int speed);
    ~Ball();

    /* methods */
    pair<int, int> get_ball_dimension();
    pair<int, int> get_ball_position();
    void set_update_ball_position(pair<int, int> updated_position);
    int get_ball_speed();
    void update_ball_direction(int new_direction);
    int get_ball_direction();
};

#endif