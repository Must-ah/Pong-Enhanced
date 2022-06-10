#ifndef PLAY_HPP
#define PLAY_HPP

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

public:
    Play(/* args */);
    Play(Pong &pong);
    ~Play();

    /* methods */
    void render(Pong &pong);
    void render(Player &player);
    void render(Ball &ball);
    void render(Pong &pong, TTF_Font* &font);

    void restart_game(Pong &pong);
    void update_score(Pong &pong, pair<int, int> updated_score);
};

#endif