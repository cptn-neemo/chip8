CC = g++
BUILDDIR = ../build
FLAGS = -Wall -Werror -g
SDL = `sdl2-config --cflags --libs`

SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)

target: $(OBJ)

%.o: %.cpp
	$(CC) -o $(BUILDDIR)/$@ -c $^ $(FLAGS) $(SDL)
