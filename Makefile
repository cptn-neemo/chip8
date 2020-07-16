CC = g++
FLAGS = -Wall -Werror -g
SDL = `sdl2-config --cflags --libs`
OPCODE_DIR = opcode/
DISPLAY_DIR = display/
TEST_DIR = tests/

target: chip8.h chip8.cpp OpcodeTable.o build/*.o
	$(MAKE) -C $(OPCODE_DIR)
	$(MAKE) -C $(DISPLAY_DIR)
	$(CC) -o build/chip8 chip8.h chip8.cpp build/*.o  $(FLAGS) $(SDL)
OpcodeTable.o : OpcodeTable.h OpcodeTable.cpp
	$(CC) -o build/OpcodeTable.o -c OpcodeTable.cpp $(SDL) $(FLAGS)
Display.o : display/Display.h display/Display.cpp
	$(CC) -o build/Display.o -c display/Display.cpp $(SDL) $(FLAGS)

SDLPointer.o : display/SDLPointer.h display/SDLPointer.cpp
	$(CC) -o build/SDLPointer.o -c display/SDLPointer.cpp $(SDL) $(FLAGS)


run: target
	build/chip8
clean: 
	rm -f *.o
	rm chip8

test: target
	$(MAKE) -C $(TEST_DIR)
	tests/tests
