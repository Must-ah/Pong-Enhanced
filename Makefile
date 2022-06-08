CC = g++
FLAGS = -std=c++17 -Wall -pedantic -g -fext-numeric-literals -fsanitize=leak,undefined,address
VALGRIND = valgrind --leak-check=yes -v --track-origins=yes

main:
	$(CC) $(FLAGS) -o main main.cpp