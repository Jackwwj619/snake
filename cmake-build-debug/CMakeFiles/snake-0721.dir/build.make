# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /tmp/tmp.mWndTV01KL

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /tmp/tmp.mWndTV01KL/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/snake-0721.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/snake-0721.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/snake-0721.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/snake-0721.dir/flags.make

CMakeFiles/snake-0721.dir/src/snakeMove.c.o: CMakeFiles/snake-0721.dir/flags.make
CMakeFiles/snake-0721.dir/src/snakeMove.c.o: ../src/snakeMove.c
CMakeFiles/snake-0721.dir/src/snakeMove.c.o: CMakeFiles/snake-0721.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/tmp.mWndTV01KL/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/snake-0721.dir/src/snakeMove.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/snake-0721.dir/src/snakeMove.c.o -MF CMakeFiles/snake-0721.dir/src/snakeMove.c.o.d -o CMakeFiles/snake-0721.dir/src/snakeMove.c.o -c /tmp/tmp.mWndTV01KL/src/snakeMove.c

CMakeFiles/snake-0721.dir/src/snakeMove.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/snake-0721.dir/src/snakeMove.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /tmp/tmp.mWndTV01KL/src/snakeMove.c > CMakeFiles/snake-0721.dir/src/snakeMove.c.i

CMakeFiles/snake-0721.dir/src/snakeMove.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/snake-0721.dir/src/snakeMove.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /tmp/tmp.mWndTV01KL/src/snakeMove.c -o CMakeFiles/snake-0721.dir/src/snakeMove.c.s

CMakeFiles/snake-0721.dir/src/sys.c.o: CMakeFiles/snake-0721.dir/flags.make
CMakeFiles/snake-0721.dir/src/sys.c.o: ../src/sys.c
CMakeFiles/snake-0721.dir/src/sys.c.o: CMakeFiles/snake-0721.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/tmp.mWndTV01KL/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/snake-0721.dir/src/sys.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/snake-0721.dir/src/sys.c.o -MF CMakeFiles/snake-0721.dir/src/sys.c.o.d -o CMakeFiles/snake-0721.dir/src/sys.c.o -c /tmp/tmp.mWndTV01KL/src/sys.c

CMakeFiles/snake-0721.dir/src/sys.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/snake-0721.dir/src/sys.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /tmp/tmp.mWndTV01KL/src/sys.c > CMakeFiles/snake-0721.dir/src/sys.c.i

CMakeFiles/snake-0721.dir/src/sys.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/snake-0721.dir/src/sys.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /tmp/tmp.mWndTV01KL/src/sys.c -o CMakeFiles/snake-0721.dir/src/sys.c.s

CMakeFiles/snake-0721.dir/main.c.o: CMakeFiles/snake-0721.dir/flags.make
CMakeFiles/snake-0721.dir/main.c.o: ../main.c
CMakeFiles/snake-0721.dir/main.c.o: CMakeFiles/snake-0721.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/tmp.mWndTV01KL/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/snake-0721.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/snake-0721.dir/main.c.o -MF CMakeFiles/snake-0721.dir/main.c.o.d -o CMakeFiles/snake-0721.dir/main.c.o -c /tmp/tmp.mWndTV01KL/main.c

CMakeFiles/snake-0721.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/snake-0721.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /tmp/tmp.mWndTV01KL/main.c > CMakeFiles/snake-0721.dir/main.c.i

CMakeFiles/snake-0721.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/snake-0721.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /tmp/tmp.mWndTV01KL/main.c -o CMakeFiles/snake-0721.dir/main.c.s

# Object files for target snake-0721
snake__0721_OBJECTS = \
"CMakeFiles/snake-0721.dir/src/snakeMove.c.o" \
"CMakeFiles/snake-0721.dir/src/sys.c.o" \
"CMakeFiles/snake-0721.dir/main.c.o"

# External object files for target snake-0721
snake__0721_EXTERNAL_OBJECTS =

snake-0721: CMakeFiles/snake-0721.dir/src/snakeMove.c.o
snake-0721: CMakeFiles/snake-0721.dir/src/sys.c.o
snake-0721: CMakeFiles/snake-0721.dir/main.c.o
snake-0721: CMakeFiles/snake-0721.dir/build.make
snake-0721: /usr/lib/x86_64-linux-gnu/libcurses.so
snake-0721: /usr/lib/x86_64-linux-gnu/libform.so
snake-0721: CMakeFiles/snake-0721.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/tmp/tmp.mWndTV01KL/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable snake-0721"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/snake-0721.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/snake-0721.dir/build: snake-0721
.PHONY : CMakeFiles/snake-0721.dir/build

CMakeFiles/snake-0721.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/snake-0721.dir/cmake_clean.cmake
.PHONY : CMakeFiles/snake-0721.dir/clean

CMakeFiles/snake-0721.dir/depend:
	cd /tmp/tmp.mWndTV01KL/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /tmp/tmp.mWndTV01KL /tmp/tmp.mWndTV01KL /tmp/tmp.mWndTV01KL/cmake-build-debug /tmp/tmp.mWndTV01KL/cmake-build-debug /tmp/tmp.mWndTV01KL/cmake-build-debug/CMakeFiles/snake-0721.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/snake-0721.dir/depend
