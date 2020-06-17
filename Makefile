CC = g++
FLAGS = -Wall -Werror -g

target: chip8.h chip8.cpp
	$(CC) -o chip8 chip8.h chip8.cpp $(FLAGS)
