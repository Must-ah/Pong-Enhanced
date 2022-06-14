#ifndef PLAY_HPP
#define PLAY_HPP

#include <iostream>
using std::cout;
using std::endl;

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include <assert.h>

#include <string>
using std::string;
using std::to_string;

#include "Pong.hpp"
#include "Player.hpp"
//#include "Ball.hpp"

class Play
{
private:
    /* data */
    SDL_Renderer *renderer;
    SDL_Window *window;
    TTF_Font *font;
    SDL_Color color;
    bool running;
    int font_size;

    /* Methods*/
    void init_SDL(Pong &pong);
    void init_TTF(const int &size_font);
    void update(Ball &ball);
    void update(Player &player);
    SDL_Rect get_SDL_Rect_element(Ball &ball);
    SDL_Rect get_SDL_Rect_element(Player &player);
    SDL_Rect get_SDL_Rect_element(Board &board);

public:
    Play(/* args */);
    Play(Pong &pong);
    ~Play();

    /* methods */
    void render(Pong &pong);
    void render_new_game(Pong &pong);
    void render(Player &player);
    void render(Ball &ball);
    void render(Pong &pong, TTF_Font *&font);

    void get_input(Pong &pong);
    void restart_game(Pong &pong);
    void update_score(Pong &pong, pair<int, int> updated_score);
    bool is_running();
    void update_game_state(Pong &pong);

    bool object_intersection(Ball &ball, Player &player);
    bool object_intersection(Ball &ball, Board &board);
    bool object_intersection(Player &player, Board &board);
};

#endif