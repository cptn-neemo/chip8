CC = g++
BUILDDIR = ../build

SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)

target: $(OBJ)

%.o: %.cpp
	$(CC) -o $(BUILDDIR)/$@ -c $^
