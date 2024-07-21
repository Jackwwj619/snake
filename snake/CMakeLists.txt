
cmake_minimum_required(VERSION 3.10)
project(snake C)

# 寻找curses的库
find_package(Curses REQUIRED)
# 包含curses的库
include_directories(${CURSES_INCLUDE_DIR})
# 包含项目的.h
include_directories(${PROJECT_SOURCE_DIR}/include)


# 拷贝资源文件
FILE(COPY res DESTINATION "${CMAKE_BINARY_DIR}")

# 搜索src目录下的所有文件，赋值给变量SRC_LIST
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/src SRC_LIST)
# 添加库文件，把src生成静态链接库
add_library(SOURCE_LIB STATIC main.c ${SRC_LIST}
        src/game.c
        include/nwindow.h
        src/key.c
        src/SnakeMove.c
)

# 使用pthread
set(CMAKE_C_FLAGS -pthread)
set(CMAKE_C_STANDARD 11)

add_executable(snake main.c
        include/key.h
        include/game.h
        include/ranking.h
        include/SnakeMove.h)
# link其他库，包括上面定义的Source_LIB,m-数学库, curses库
target_link_libraries(snake ${CURSES_LIBRARIES} SOURCE_LIB m)