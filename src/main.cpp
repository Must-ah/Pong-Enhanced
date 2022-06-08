#include "../include/board.hpp"
#include "../include/Player.hpp"
#include "../include/Pong.hpp"
#include <iostream>
using std::cout;
using std::endl;

int main(int argc, char const *argv[])
{
    Pong pong {1600, 900};
    const auto& [width, height] = pong.get_board_dimensions();
    cout << "width: " << width << endl;
    return 0;
}
