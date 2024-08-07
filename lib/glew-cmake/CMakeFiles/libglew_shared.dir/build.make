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
CMAKE_SOURCE_DIR = "/home/user/Projects/C++ labs/Rubik-s-Cube"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/user/Projects/C++ labs/Rubik-s-Cube"

# Include any dependencies generated for this target.
include lib/glew-cmake/CMakeFiles/libglew_shared.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include lib/glew-cmake/CMakeFiles/libglew_shared.dir/compiler_depend.make

# Include the progress variables for this target.
include lib/glew-cmake/CMakeFiles/libglew_shared.dir/progress.make

# Include the compile flags for this target's objects.
include lib/glew-cmake/CMakeFiles/libglew_shared.dir/flags.make

lib/glew-cmake/CMakeFiles/libglew_shared.dir/src/glew.c.o: lib/glew-cmake/CMakeFiles/libglew_shared.dir/flags.make
lib/glew-cmake/CMakeFiles/libglew_shared.dir/src/glew.c.o: lib/glew-cmake/src/glew.c
lib/glew-cmake/CMakeFiles/libglew_shared.dir/src/glew.c.o: lib/glew-cmake/CMakeFiles/libglew_shared.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/user/Projects/C++ labs/Rubik-s-Cube/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object lib/glew-cmake/CMakeFiles/libglew_shared.dir/src/glew.c.o"
	cd "/home/user/Projects/C++ labs/Rubik-s-Cube/lib/glew-cmake" && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT lib/glew-cmake/CMakeFiles/libglew_shared.dir/src/glew.c.o -MF CMakeFiles/libglew_shared.dir/src/glew.c.o.d -o CMakeFiles/libglew_shared.dir/src/glew.c.o -c "/home/user/Projects/C++ labs/Rubik-s-Cube/lib/glew-cmake/src/glew.c"

lib/glew-cmake/CMakeFiles/libglew_shared.dir/src/glew.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/libglew_shared.dir/src/glew.c.i"
	cd "/home/user/Projects/C++ labs/Rubik-s-Cube/lib/glew-cmake" && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/user/Projects/C++ labs/Rubik-s-Cube/lib/glew-cmake/src/glew.c" > CMakeFiles/libglew_shared.dir/src/glew.c.i

lib/glew-cmake/CMakeFiles/libglew_shared.dir/src/glew.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/libglew_shared.dir/src/glew.c.s"
	cd "/home/user/Projects/C++ labs/Rubik-s-Cube/lib/glew-cmake" && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/user/Projects/C++ labs/Rubik-s-Cube/lib/glew-cmake/src/glew.c" -o CMakeFiles/libglew_shared.dir/src/glew.c.s

# Object files for target libglew_shared
libglew_shared_OBJECTS = \
"CMakeFiles/libglew_shared.dir/src/glew.c.o"

# External object files for target libglew_shared
libglew_shared_EXTERNAL_OBJECTS =

lib/glew-cmake/lib/libglew-shared.so.2.2.0: lib/glew-cmake/CMakeFiles/libglew_shared.dir/src/glew.c.o
lib/glew-cmake/lib/libglew-shared.so.2.2.0: lib/glew-cmake/CMakeFiles/libglew_shared.dir/build.make
lib/glew-cmake/lib/libglew-shared.so.2.2.0: /usr/lib/x86_64-linux-gnu/libOpenGL.so
lib/glew-cmake/lib/libglew-shared.so.2.2.0: /usr/lib/x86_64-linux-gnu/libGLX.so
lib/glew-cmake/lib/libglew-shared.so.2.2.0: /usr/lib/x86_64-linux-gnu/libX11.so
lib/glew-cmake/lib/libglew-shared.so.2.2.0: /usr/lib/x86_64-linux-gnu/libXext.so
lib/glew-cmake/lib/libglew-shared.so.2.2.0: /usr/lib/x86_64-linux-gnu/libOpenGL.so
lib/glew-cmake/lib/libglew-shared.so.2.2.0: /usr/lib/x86_64-linux-gnu/libX11.so
lib/glew-cmake/lib/libglew-shared.so.2.2.0: lib/glew-cmake/CMakeFiles/libglew_shared.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/user/Projects/C++ labs/Rubik-s-Cube/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C shared library lib/libglew-shared.so"
	cd "/home/user/Projects/C++ labs/Rubik-s-Cube/lib/glew-cmake" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/libglew_shared.dir/link.txt --verbose=$(VERBOSE)
	cd "/home/user/Projects/C++ labs/Rubik-s-Cube/lib/glew-cmake" && $(CMAKE_COMMAND) -E cmake_symlink_library lib/libglew-shared.so.2.2.0 lib/libglew-shared.so.2.2.0 lib/libglew-shared.so

lib/glew-cmake/lib/libglew-shared.so: lib/glew-cmake/lib/libglew-shared.so.2.2.0
	@$(CMAKE_COMMAND) -E touch_nocreate lib/glew-cmake/lib/libglew-shared.so

# Rule to build all files generated by this target.
lib/glew-cmake/CMakeFiles/libglew_shared.dir/build: lib/glew-cmake/lib/libglew-shared.so
.PHONY : lib/glew-cmake/CMakeFiles/libglew_shared.dir/build

lib/glew-cmake/CMakeFiles/libglew_shared.dir/clean:
	cd "/home/user/Projects/C++ labs/Rubik-s-Cube/lib/glew-cmake" && $(CMAKE_COMMAND) -P CMakeFiles/libglew_shared.dir/cmake_clean.cmake
.PHONY : lib/glew-cmake/CMakeFiles/libglew_shared.dir/clean

lib/glew-cmake/CMakeFiles/libglew_shared.dir/depend:
	cd "/home/user/Projects/C++ labs/Rubik-s-Cube" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/user/Projects/C++ labs/Rubik-s-Cube" "/home/user/Projects/C++ labs/Rubik-s-Cube/lib/glew-cmake" "/home/user/Projects/C++ labs/Rubik-s-Cube" "/home/user/Projects/C++ labs/Rubik-s-Cube/lib/glew-cmake" "/home/user/Projects/C++ labs/Rubik-s-Cube/lib/glew-cmake/CMakeFiles/libglew_shared.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : lib/glew-cmake/CMakeFiles/libglew_shared.dir/depend

