# C++ 编译器，默认使用 g++。
CXX ?= g++
# 通用编译选项：C++17、常用警告和严格标准检查。
CXXFLAGS ?= -std=c++17 -Wall -Wextra -pedantic

# 最终生成的可执行文件名。
TARGET := user_app
# 链接可执行文件所需的目标文件。
OBJS := main.o user.o

# 默认目标：构建最终可执行文件。
all: $(TARGET)

# 链接规则：把 main.o 和 user.o 链接为 user_app。
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@

# 编译规则：main.cpp 依赖 user.h，生成 main.o。
main.o: main.cpp user.h
	$(CXX) $(CXXFLAGS) -c main.cpp -o $@

# 编译规则：user.cpp 依赖 user.h，生成 user.o。
user.o: user.cpp user.h
	$(CXX) $(CXXFLAGS) -c user.cpp -o $@

# 清理规则：删除可执行文件和目标文件。
clean:
	rm -f $(TARGET) $(OBJS)

# all 和 clean 是命令目标，不是实际文件名。
.PHONY: all clean
