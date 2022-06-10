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
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    Player human_player = pong.get_human_player();
    render(human_player);
    
    Player ai = pong.get_AI_player();
    render(ai);    

    SDL_RenderPresent(renderer);
}

void Play::render(Player &player)
{    
    const auto &[player_width, player_height] = player.get_player_dimension();
    SDL_Rect player_SDL;
    player_SDL.w = player_width;
    player_SDL.h = player_height;
    
    const auto &[player_x, player_y] = player.get_player_position();
    player_SDL.x = player_x;
    player_SDL.y = player_y;
    SDL_RenderFillRect(renderer, &player_SDL);
}

Play::~Play()
{
    TTF_CloseFont(font);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}