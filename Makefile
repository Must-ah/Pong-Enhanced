CC = g++
FLAGS = -std=c++20 -Wall -pedantic -g -fext-numeric-literals -fsanitize=leak,undefined,address
VALGRIND = valgrind --leak-check=yes -v --track-origins=yes
SRC_DIR = ./src/
OUT_DIR = ./build/



main: $(SRC_DIR)main.cpp Board.o Player.o Pong.o
	$(CC) $(FLAGS) ./src/main.cpp $(OUT_DIR)board.o $(OUT_DIR)Pong.o $(OUT_DIR)Player.o -o $(OUT_DIR)main.out

Board.o: ./src/board.cpp
	$(CC) $(FLAGS) -c  $(SRC_DIR)board.cpp -o $(OUT_DIR)board.o

Player.o: ./src/Player.cpp
	$(CC) $(FLAGS) -c  $(SRC_DIR)Player.cpp -o $(OUT_DIR)Player.o

Pong.o : ./src/Pong.cpp
	$(CC) $(FLAGS) -c  $(SRC_DIR)Pong.cpp -o $(OUT_DIR)Pong.o

clean:
	rm -f $(OUT_DIR)*.o $(OUT_DIR)*.out
run: main
	$(OUT_DIR)main.out