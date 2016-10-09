
CXX = g++
CXXFLAGS = -Wall -Wextra -pedantic -ggdb -Wno-unused-but-set-parameter -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function -Wno-abi
LDFLAGS =
LDFLAGSTESTS = -pthread -lgtest
BINDIR = ./bin/
SRCDIR = ./src/
INCDIR = ./include/
SCRIPTDIR = ./scripts/
TESTSMAIN = ./tests/MainTest.cpp
SRCFILES = $(wildcard *.cpp)
OBJFILES = $(SRC:.cpp=.o)

.PHONY: clean

test:
	$(CXX) $(TESTSMAIN) -I$(SRCDIR) -I$(INCDIR) -o ./tests/tests $(LDFLAGSTESTS)
	./tests/tests
	valgrind ./tests/tests

merge:
	echo "Hello Travis!"

clean :
	rm -rf $(BINDIR)
