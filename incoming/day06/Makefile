# C++ 编译器，默认使用 g++。
CXX ?= g++
# 通用编译选项：C++17、常用警告和严格标准检查。
CXXFLAGS ?= -std=c++17 -Wall -Wextra -pedantic

# all 和 clean 是命令目标，不是实际文件名。
.PHONY: all clean

# 默认目标：构建三个错误处理演示程序。
all: error_demo retry_demo bind_port_demo

# 编译 errno 和 perror 演示程序。
error_demo: error_demo.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

# 编译 EINTR 重试演示程序。
retry_demo: retry_demo.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

# 编译端口绑定演示程序。
bind_port_demo: bind_port_demo.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

# 删除三个可执行文件。
clean:
	rm -f error_demo retry_demo bind_port_demo
