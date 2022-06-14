#include "../include/Play.hpp"

Play::Play(Pong &pong)
{
    init_SDL(pong);
    font_size = 32;
    init_TTF(font_size);
    render_new_game(pong);
    // get_input();
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

void Play::render_new_game(Pong &pong)
{

    running = true;
    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 255);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    Player human_player = pong.get_human_player();
    render(human_player);

    Player ai = pong.get_AI_player();
    render(ai);

    Ball &ball = pong.get_ball();

    const auto &[board_width, board_hight] = pong.get_board_dimensions();
    int new_ball_x = board_width / 2;
    int new_ball_y = board_hight / 2;
    pair<int, int> new_ball_pos = make_pair(new_ball_x, new_ball_y);
    ball.set_update_ball_position(new_ball_pos);
    render(ball);

    render(pong, font);

    SDL_RenderPresent(renderer);
}

void Play::render(Pong &pong)
{
    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 255);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    render(pong.get_ball());
    render(pong.get_human_player());
    render(pong.get_AI_player());
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

void Play::get_input(Pong &pong)
{
    SDL_Event event;
    const Uint8 *keystates = SDL_GetKeyboardState(NULL);
    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_QUIT)
        {
            running = false;
        }
    }
    if (keystates[SDL_SCANCODE_ESCAPE])
    {
        running = false;
    }
    if (keystates[SDL_SCANCODE_K])
    {
        int current_speed = -std::abs(pong.get_human_player().get_speed());
        pong.get_human_player().set_speed(current_speed);
        update(pong.get_human_player());
        cout << "Key K pressed"
             << endl;
    }
    if (keystates[SDL_SCANCODE_J])
    {
        int current_speed = std::abs(pong.get_human_player().get_speed());
        pong.get_human_player().set_speed(current_speed);
        update(pong.get_human_player());
        cout << "Key J pressed"
             << endl;
    }
}
bool Play::is_running()
{
    return running;
}

void Play::restart_game(Pong &pong)
{
    pong.reset_game();
}

SDL_Rect Play::get_SDL_Rect_element(Ball &ball)
{
    SDL_Rect ball_SDL;
    const auto &[ball_x, ball_y] = ball.get_ball_position();
    ball_SDL.x = ball_x;
    ball_SDL.y = ball_y;
    const auto &[ball_width, ball_height] = ball.get_ball_dimension();
    ball_SDL.w = ball_width;
    ball_SDL.h = ball_height;
    return ball_SDL;
}

SDL_Rect Play::get_SDL_Rect_element(Player &player)
{
    SDL_Rect player_SDL;
    const auto &[player_x, player_y] = player.get_player_position();
    player_SDL.x = player_x;
    player_SDL.y = player_y;
    const auto &[player_width, player_height] = player.get_player_dimension();
    player_SDL.w = player_width;
    player_SDL.h = player_height;
    return player_SDL;
}

SDL_Rect Play::get_SDL_Rect_element(Board &board)
{
    SDL_Rect board_SDL;
    const auto &[board_width, board_height] = board.get_dimensions();
    board_SDL.w = board_width;
    board_SDL.h = board_height;
    board_SDL.x = 0;
    board_SDL.y = 0;
    return board_SDL;
}

bool Play::object_intersection(Ball &ball, Player &player)
{
    SDL_Rect ball_SDL = get_SDL_Rect_element(ball);
    SDL_Rect player_SDL = get_SDL_Rect_element(player);

    return SDL_HasIntersection(&ball_SDL, &player_SDL);
}

bool Play::object_intersection(Ball &ball, Board &board)
{
    SDL_Rect board_SDL = get_SDL_Rect_element(board);
    SDL_Rect ball_SDL = get_SDL_Rect_element(ball);

    return SDL_HasIntersection(&ball_SDL, &board_SDL);
}

bool Play::object_intersection(Player &player, Board &board)
{
    SDL_Rect board_SDL = get_SDL_Rect_element(board);
    SDL_Rect player_SDL = get_SDL_Rect_element(player);

    return SDL_HasIntersection(&player_SDL, &board_SDL);
}

void Play::update_game_state(Pong &pong)
{
    bool continue_play = running;
    int frame_count = 0;
    int last_frame = 0;
    int last_time = 0;

    Ball &ball = pong.get_ball();
    while (continue_play)
    {
        last_frame = SDL_GetTicks();
        if (last_frame >= (last_time + 1000))
        {
            last_time = last_frame;
            frame_count = 0;
        }
        get_input(pong);
        continue_play = running;
        ++frame_count;
        int time_fps = SDL_GetTicks() - last_frame;
        if (time_fps < 1000 / 60)
        {
            SDL_Delay((1000 / 60) - time_fps);
        }
        update(ball);
        bool player_within_board = object_intersection(pong.get_human_player(), pong.get_board());
        if (!player_within_board)
        {
            const auto &[player_x, player_y] = pong.get_human_player().get_player_position();
            const auto &[player_width, player_height] = pong.get_human_player().get_player_dimension();
            const auto &[board_width, board_height] = pong.get_board().get_dimensions();

            int new_player_y = player_y < 0 ? 0 : player_y;
            new_player_y = board_height - player_height;
            if (player_y >= board_height)
            {
                new_player_y = 0;
            }

            pong.get_human_player().update_position(make_pair(player_x, new_player_y));
        }
        bool has_intersected = object_intersection(ball, pong.get_human_player());
        if (has_intersected)
        {
            int new_ball_direction = ball.get_ball_direction() * -1;
            ball.update_ball_direction(new_ball_direction);
        }
        has_intersected = object_intersection(ball, pong.get_AI_player());
        if (has_intersected)
        {
            int new_ball_direction = ball.get_ball_direction() * -1;
            ball.update_ball_direction(new_ball_direction);
        }
        render(pong);
    }
}

void Play::update(Player &player)
{
    const auto &[player_x, player_y] = player.get_player_position();
    int new_player_y = player_y + player.get_speed();
    pair<int, int> new_player_pos = make_pair(player_x, new_player_y);
    cout << "Player position X is: "
         << player_x
         << " and Player position Y is: "
         << player_y
         << endl;

    player.update_position(new_player_pos);
}

void Play::update(Ball &ball)
{
    const auto &[ball_x, ball_y] = ball.get_ball_position();
    int ball_direction = ball.get_ball_direction();
    int new_ball_x = (ball_x >= 0) ? ball_x + ball_direction * ball.get_ball_speed() : 800;

    pair<int, int> new_ball_pos = make_pair(new_ball_x, ball_y);
    ball.set_update_ball_position(new_ball_pos);
}

Play::~Play()
{
    TTF_CloseFont(font);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
