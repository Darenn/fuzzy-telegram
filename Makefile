
CXX = g++
CXXFLAGS = -Wall -Wextra -pedantic -ggdb -Wno-unused-but-set-parameter -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-abi
LDFLAGS =
BINDIR = ./bin/
SRCDIR = ./src/
INCDIR = ./headers/
SRCFILES = $(wildcard *.cpp)
OBJFILES = $(SRC:.cpp=.o)

.PHONY: clean

clean :
	rm -rf $(BINDIR)
