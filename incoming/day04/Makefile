CXX ?= g++
CXXFLAGS ?= -std=c++17 -Wall -Wextra -pedantic

TARGET := user_app
OBJS := main.o user.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@

main.o: main.cpp user.h
	$(CXX) $(CXXFLAGS) -c main.cpp -o $@

user.o: user.cpp user.h
	$(CXX) $(CXXFLAGS) -c user.cpp -o $@

clean:
	rm -f $(TARGET) $(OBJS)

.PHONY: all clean
