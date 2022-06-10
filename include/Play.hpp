#ifndef PLAY_HPP
#define PLAY_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include <assert.h>


#include "Pong.hpp"
#include "Player.hpp"

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
};

#endif