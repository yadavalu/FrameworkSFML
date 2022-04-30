CXX := g++
CXXFLAGS := -std=c++17 -g
LDFALGS := -lsfml-graphics -lsfml-system -lsfml-window

OBJS := Platform.o Collision.o

all: $(OBJS)

example: $(OBJS) test/test.o
	cd ../SpriteSheet/ && make
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o test/test $(OBJS) test/test.o ../SpriteSheet/AnimatedSprite.o ../SpriteSheet/Animation.o

clean: 
	rm -f $(OBJS) test/test
