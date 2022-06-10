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
    font = TTF_OpenFont("./src/Peepo.ttf", size_font);
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

    Ball ball = pong.get_ball();
    const auto &[board_width, board_hight] = pong.get_board_dimensions();
    int new_ball_x = board_width / 2;
    int new_ball_y = board_hight / 2;
    pair<int, int> new_ball_pos = make_pair(new_ball_x, new_ball_y);
    ball.set_update_ball_position(new_ball_pos);
    render(ball);

    init_TTF(32);
    render(pong, font);

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

void Play::render(Ball &ball)
{
    const auto &[ball_width, ball_height] = ball.get_ball_dimension();
    SDL_Rect ball_SDL;
    ball_SDL.w = ball_width;
    ball_SDL.h = ball_height;

    const auto &[ball_x, ball_y] = ball.get_ball_position();
    ball_SDL.x = ball_x;
    ball_SDL.y = ball_y;

    SDL_RenderFillRect(renderer, &ball_SDL);
}

void Play::update_score(Pong &pong, pair<int, int> updated_score)
{
    pong.set_game_score(updated_score);
}

void Play::render(Pong &pong, TTF_Font *&font)
{
    const auto &[human_score, ai_score] = pong.get_game_score();
    assert(font != NULL);

    string score_as_str = to_string(human_score) + "   " + to_string(ai_score);
    auto char_score = score_as_str.c_str();

    SDL_Color color;
    color.r = 255;
    color.g = 255;
    color.b = 255;

    SDL_Surface *surface = TTF_RenderText_Solid(font, char_score, color);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_Rect score_board;
    score_board.w = surface->w;
    score_board.h = surface->h;
    const auto &[board_width, board_height] = pong.get_board_dimensions();
    int temp_x = (board_width / 2) + 32;
    score_board.x = temp_x - score_board.w;
    int temp_y = 32 * 2;
    score_board.y = temp_y - score_board.h;
    SDL_FreeSurface(surface);
    SDL_RenderCopy(renderer, texture, NULL, &score_board);
    SDL_DestroyTexture(texture);
}

void Play::restart_game(Pong &pong)
{
    pong.reset_game();
}

Play::~Play()
{
    TTF_CloseFont(font);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}