#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <assert.h>

#include <utility>
using std::make_pair;
using std::pair;

class Player
{
private:
    /* data */
    pair<int, int> player_dimension;
    pair<int, int> player_position;
    int speed;

    /*methods*/
    void assert_player();

public:
    Player(/* args */);
    Player(int width, int height, int x, int y, int speed);
    ~Player(){};
    pair<int, int> get_player_dimension();
    pair<int, int> get_player_position();
    void update_position(pair<int, int> new_position);

    void set_speed(int new_speed);
    int get_speed();
};

#endif // PLAYER_HPP