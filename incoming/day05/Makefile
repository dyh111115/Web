CXX ?= g++
CXXFLAGS ?= -std=c++17 -Wall -Wextra -pedantic

.PHONY: all clean

all: fd_demo fork_demo thread_demo

fd_demo: fd_demo.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

fork_demo: fork_demo.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

thread_demo: thread_demo.cpp
	$(CXX) $(CXXFLAGS) -pthread $< -o $@

clean:
	rm -f fd_demo fork_demo thread_demo
