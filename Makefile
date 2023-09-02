CXX := g++
CXXFLAGS := -std=c++11 -Wall -Wextra

SRCS := main.cpp
OBJS := $(SRCS:.cpp=.o)
EXEC := main

.PHONY: all clean test

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(EXEC)

test: all
	./$(EXEC)
