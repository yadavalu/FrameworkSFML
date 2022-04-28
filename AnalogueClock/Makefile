CXX = g++
CXXFLAGS = -g
LIBS = -lsfml-window -lsfml-system -lsfml-graphics
OBJS = Clock.o
TESTFILE = test/main.o
TESTOUT = test/test

all: clean $(OBJS) example

example: $(TESTFILE)
	$(CXX) $(TESTFILE) $(LIBS) $(CXXFLAGS) -o $(TESTOUT) $(OBJS)
clean:
	rm -rf $(OBJS) $(TESTOUT)
