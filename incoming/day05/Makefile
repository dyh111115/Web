# C++ 编译器，默认使用 g++。
CXX ?= g++
# 通用编译选项：C++17、常用警告和严格标准检查。
CXXFLAGS ?= -std=c++17 -Wall -Wextra -pedantic

# all 和 clean 是命令目标，不是实际文件名。
.PHONY: all clean

# 默认目标：构建三个演示程序。
all: fd_demo fork_demo thread_demo

# 编译 fd_demo.cpp。
fd_demo: fd_demo.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

# 编译 fork_demo.cpp。
fork_demo: fork_demo.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

# 编译线程程序时需要链接 pthread 线程库。
thread_demo: thread_demo.cpp
	$(CXX) $(CXXFLAGS) -pthread $< -o $@

# 删除三个可执行文件。
clean:
	rm -f fd_demo fork_demo thread_demo
