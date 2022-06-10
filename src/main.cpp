#include "../include/board.hpp"
#include "../include/Player.hpp"
#include "../include/Pong.hpp"
#include "../include/Play.hpp"

#include <iostream>
using std::cout;
using std::endl;

#include <chrono>
using namespace std::chrono_literals;

#include <condition_variable>

#include <atomic>
#include <thread>

int main(int argc, char const *argv[])
{

    Pong pong{1600, 900};
    Play play(pong);
    const auto &[width, height] = pong.get_board_dimensions();
    cout << "width: " << width
         << " height: " << height
         << endl;


    
    std::condition_variable cv;
    std::mutex cv_m;
    std::atomic<int> i{0};
    auto waits = [&](int idx) -> void
    {
        std::unique_lock<std::mutex> lk(cv_m);
        auto now = std::chrono::system_clock::now();
        if (cv.wait_until(lk, now + idx * 20s, [&]()
                          { return i == 1; }))
        {
            std::cerr << "Thread "
                      << idx
                      << " finished waiting. i == "
                      << i << "\n"
                      << std::flush;
        }
        else
        {
            std::cerr << "Thread "
                      << idx
                      << "  timed out. i == "
                      << i << "\n"
                      << std::flush;
        }
    };

    auto signals = [&]() -> void
    {
        std::this_thread::sleep_for(1s);
        std::cerr << "Notifying.. \n";
        cv.notify_all();
        std::this_thread::sleep_for(2s);
        i = 1;
        std::cerr << "Notifying again...\n";
        cv.notify_all();
    };

    std::thread t1(waits, 1), t2(waits, 2), t3(waits, 3), t4(signals);
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    play.~Play();
    return 0;
}
