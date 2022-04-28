CXX := g++
CXXFLAGS := -std=c++17 -g
LDFLAGS := -lsfml-system -lsfml-graphics -lsfml-window

OBJS := Animation.o AnimatedSprite.o

all: $(OBJS)

example: $(OBJS) test/test.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o test/test $(OBJS) test/test.o 
	cd test && ./test

clean:
	rm -f $(OBJS) test/test.o
