BINARY = ../bistromathique

CXX = clang++
CXXFLAGS = -std=c++11 -Weverything -O3 -march=native

SRC = main.cc utils.cc
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
