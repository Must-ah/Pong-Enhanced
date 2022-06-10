CC = g++
FLAGS = -std=c++20 -Wall -pedantic -g -fext-numeric-literals -fsanitize=leak,undefined,address
VALGRIND = valgrind --leak-check=yes -v --track-origins=yes --show-reachable=yes
SRC_DIR = ./src/
OUT_DIR = ./build/
SDL2 = -lSDL2 -lSDL2_ttf


main: $(SRC_DIR)main.cpp Board.o Player.o Pong.o Play.o Ball.o
	$(CC) $(FLAGS) ./src/main.cpp $(OUT_DIR)board.o $(OUT_DIR)Pong.o $(OUT_DIR)Player.o $(OUT_DIR)Play.o $(OUT_DIR)Ball.o  $(SDL2) -o $(OUT_DIR)main.out

Board.o: $(SRC_DIR)board.cpp
	$(CC) $(FLAGS) -c  $(SRC_DIR)board.cpp -o $(OUT_DIR)board.o

Player.o: $(SRC_DIR)Player.cpp
	$(CC) $(FLAGS) -c  $(SRC_DIR)Player.cpp -o $(OUT_DIR)Player.o

Pong.o : $(SRC_DIR)Pong.cpp
	$(CC) $(FLAGS) -c  $(SRC_DIR)Pong.cpp -o $(OUT_DIR)Pong.o

Ball.o : $(SRC_DIR)Ball.cpp
	$(CC) $(FLAGS) -c  $(SRC_DIR)Ball.cpp -o $(OUT_DIR)Ball.o

Play.o: $(SRC_DIR)Play.cpp
	$(CC) $(FLAGS) -c  $(SRC_DIR)Play.cpp -o $(OUT_DIR)Play.o

valgrind: 
	$(VALGRIND) $(OUT_DIR)main.out

clean:
	rm -f $(OUT_DIR)*.o $(OUT_DIR)*.out
run: clean main
	$(OUT_DIR)main.out