
CXX = clang
CXXFLAGS = -Wall -Wextra -pedantic -ggdb -Wno-unused-but-set-parameter -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-abi
LDFLAGS =
BINDIR = ./bin/
SRCDIR = ./src/
INCDIR = ./include/
SCRIPTDIR = ./scripts/
SRCFILES = $(wildcard *.cpp)
OBJFILES = $(SRC:.cpp=.o)

.PHONY: clean

merge:
	echo "Hello Travis!"

clean :
	rm -rf $(BINDIR)
