#include "../include/Play.hpp"

Play::Play(Pong &pong)
{
    init_SDL(pong);
    font_size = 32;
    init_TTF(font_size);
    render(pong);
}

void Play::init_SDL(Pong &pong)
{
    assert(SDL_Init(SDL_INIT_EVERYTHING) >= 0);
    auto const &[width, height] = pong.get_board_dimensions();
    auto Create_Window_Render_Successfully = SDL_CreateWindowAndRenderer(width,
                                                                         height,
                                                                         SDL_WINDOW_SHOWN,
                                                                         &window, &renderer);

    assert(Create_Window_Render_Successfully >= 0);

    SDL_SetWindowTitle(window, "Pong Enhanced");
    SDL_ShowCursor(0);
}

void Play::init_TTF(const int &size_font)
{
    TTF_Init();
    font = TTF_OpenFont("../include/Peepo.ttf", size_font);
}

void Play::render(Pong &pong)
{
    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 255);
    SDL_RenderClear(renderer);
    SDL_Delay(5 / 60);
    Player human = pong.get_human_player();
    const auto &[width, height] = human.get_player_dimension();
    SDL_Rect human_SDL;
    human_SDL.h = height;
    human_SDL.w = 12;
    human_SDL.x = 32;
    human_SDL.y = (900 / 2) - (human_SDL.h / 2);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, &human_SDL);
    SDL_RenderPresent(renderer);
}

Play::~Play()
{
    TTF_CloseFont(font);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}