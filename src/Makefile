BINARY = ../bistromathique

CXX = clang++
#CXXFLAGS = -std=c++11 -Oz -Wno-shift-count-overflow -D_DEBUG
CXXFLAGS = -std=c++11 -O0 -g -Wno-shift-count-overflow
#CXXFLAGS = -std=c++11 -Wall -Wextra -pedantic -O3 -march=native -Wno-shift-count-overflow

SRC = main.cc utils.cc Lexer.cc Parser.cc
OBJ = $(SRC:.cc=.o)
CLEAN = $(OBJ)

all: $(BINARY)
	$(CXX) $(CXXFLAGS) -o $(BINARY) $(OBJ)

$(BINARY): $(OBJ)

.o:.cc
	$(CXX) $(CXXFLAGS) -o $@ $<

clean:
	@rm -frv $(CLEAN)

distclean: clean
	@rm -frv $(BINARY)
