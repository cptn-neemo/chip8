CC = g++
FLAGS = -Wall -Werror -g

target: chip8.h chip8.cpp opcode.o
	$(CC) -o chip8 chip8.h chip8.cpp opcode.o $(FLAGS)
opcode.o : opcode.h opcode.cpp
	$(CC) -o opcode.o -c opcode.cpp
