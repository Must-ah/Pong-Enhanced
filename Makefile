CC = g++
FLAGS = -std=c++20 -Wall -pedantic -g -fext-numeric-literals -fsanitize=leak,undefined,address
VALGRIND = valgrind --leak-check=yes -v --track-origins=yes
SOURCE_DIC = -I/src/



main: ./src/main.cpp Board.o Player.o Pong.o
	$(CC) $(FLAGS) ./src/main.cpp ./board.o Pong.o Player.o -o main.out

Board.o: ./src/board.cpp
	$(CC) $(FLAGS) -c  ./src/board.cpp

Player.o: ./src/Player.cpp
	$(CC) $(FLAGS) -c  ./src/Player.cpp

Pong.o : ./src/Pong.cpp
	$(CC) $(FLAGS) -c  ./src/Pong.cpp