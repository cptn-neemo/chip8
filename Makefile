CC = g++
FLAGS = -Wall -Werror -g
SDL = `sdl2-config --cflags --libs`


target: chip8.h chip8.cpp opcode.o Display.o SDLPointer.o
	$(CC) -o build/chip8 chip8.h chip8.cpp build/opcode.o build/Display.o build/SDLPointer.o $(FLAGS) $(SDL)
opcode.o : opcode.h opcode.cpp
	$(CC) -o build/opcode.o -c opcode.cpp $(SDL)
Display.o : display/Display.h display/Display.cpp
	$(CC) -o build/Display.o -c display/Display.cpp $(SDL)

SDLPointer.o : display/SDLPointer.h display/SDLPointer.cpp
	$(CC) -o build/SDLPointer.o -c display/SDLPointer.cpp $(SDL)

make run: target
	build/chip8
clean: 
	rm -f *.o
	rm chip8
