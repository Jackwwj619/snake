cmake_minimum_required(VERSION 3.17)
project(snake-0721 C)


set(CMAKE_C_STANDARD 99)

# 寻找curses的库
find_package(Curses REQUIRED)
# 包含curses的库
include_directories(${CURSES_INCLUDE_DIR})
include_directories(${CMAKE_SOURCE_DIR}/include)

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/src SRC_LIST)

# 生成可执行文件，第一个参数代表可执行文件名，剩余就是使用的源文件
add_executable(snake-0721 ${SRC_LIST} main.c
        src/sys.c
        include/snakeMove.h
        src/sys.c
        src/snakeMove.c
        include/snakeMove.h
)

target_link_libraries(snake-0721 ${CURSES_LIBRARIES})
