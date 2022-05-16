CXX = g++
CXXFLAGS = -g
LIBS = -lsfml-window -lsfml-system -lsfml-graphics
OBJS = TileMap.o
TEST = test/main.o
OUT = test/test

all: $(OBJS)
example: $(TEST)
	$(CXX) $(CXXFLAGS) $(LIBS) $(TEST) $(OBJS) -o $(OUT)
clear:
	rm -rf $(OUT) $(OBJS) $(TEST)
