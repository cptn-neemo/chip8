CC = g++
FLAGS = -Wall -Werror -g
SDL = `sdl2-config --cflags --libs`
BUILDDIR = ../build
SRC=$(wildcard *.cpp)

tests: $(SRC) $(BUILDDIR)/*
	$(CC) -o tests $(SRC) $(BUILDDIR)/*.o $(SDL) -g 

