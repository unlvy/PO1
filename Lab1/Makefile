CXX = g++
EXEC = lab1
CXXFLAGS = $(flag) -std=c++14 -Wall -pedantic
SRC = $(wildcard *.cpp)
OBJS = $(SRC:.cpp=.o)

all: $(EXEC) clear run

$(EXEC): $(OBJS)
	$(CXX) $^ -o $@

error: $(EXEC) run clear
error: flag=-D ERROR

clean:
	rm -rf *.o $(EXEC)

clear:
	rm -rf *.o

run:
	./$(EXEC)

check: 
	valgrind ./$(EXEC)

.PHONY: all clean clear run check