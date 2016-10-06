
CXX = clang
CXXFLAGS = -Wall -Wextra -pedantic -ggdb -Wno-unused-but-set-parameter -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-abi
LDFLAGS =
BINDIR = ./bin/
SRCDIR = ./src/
INCDIR = ./headers/
SCRIPTDIR = ./scripts/
SRCFILES = $(wildcard *.cpp)
OBJFILES = $(SRC:.cpp=.o)

.PHONY: clean

merge:
	bash $(SCRIPTDIR)merge.sh

clean :
	rm -rf $(BINDIR)
