CC = g++
FLAGS = -std=c++20 -Wall -pedantic -g -fext-numeric-literals -fsanitize=leak,undefined,address
VALGRIND = valgrind --leak-check=yes -v --track-origins=yes
SOURCE_DIC = -I/src/



main: main.cpp Board
	$(CC) $(FLAGS) $(SOURCE_DIC) main.cpp -o main.out


Board: board.cpp
	$(CC) $(FLAGS) -o board board.cpp