CC = g++ # C++编译器的命令
CFLAGS = -Wall -g # 编译标志，-Wall启用警告，-g启用调试信息
SRC = main.cpp # 主要源文件
OBJ = main.o # 目标文件
HEADERS = SetList.h # 头文件

# 默认目标，编译可执行文件
all: myprogram

# 生成可执行文件myprogram
myprogram: $(OBJ)
$(CC) $(CFLAGS) -o $@ $(OBJ)

# 生成目标文件main.o
$(OBJ): $(SRC) $(HEADERS)
$(CC) $(CFLAGS) -c $(SRC)

# 清除编译生成的文件
clean:
rm -f $(OBJ) myprogram