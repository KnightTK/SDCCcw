# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.26

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

# Produce verbose output by default.
VERBOSE = 1

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = D:\CLion\CLion_body\bin\cmake\win\x64\bin\cmake.exe

# The command to remove a file.
RM = D:\CLion\CLion_body\bin\cmake\win\x64\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\CLion\CLion_Repository\test4

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\CLion\CLion_Repository\test4\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/RyneGame.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/RyneGame.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/RyneGame.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/RyneGame.dir/flags.make

CMakeFiles/RyneGame.dir/main.obj: CMakeFiles/RyneGame.dir/flags.make
CMakeFiles/RyneGame.dir/main.obj: D:/CLion/CLion_Repository/test4/main.cpp
CMakeFiles/RyneGame.dir/main.obj: CMakeFiles/RyneGame.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\CLion\CLion_Repository\test4\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/RyneGame.dir/main.obj"
	D:\CLion\CLion_body\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/RyneGame.dir/main.obj -MF CMakeFiles\RyneGame.dir\main.obj.d -o CMakeFiles\RyneGame.dir\main.obj -c D:\CLion\CLion_Repository\test4\main.cpp

CMakeFiles/RyneGame.dir/main.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RyneGame.dir/main.i"
	D:\CLion\CLion_body\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\CLion\CLion_Repository\test4\main.cpp > CMakeFiles\RyneGame.dir\main.i

CMakeFiles/RyneGame.dir/main.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RyneGame.dir/main.s"
	D:\CLion\CLion_body\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\CLion\CLion_Repository\test4\main.cpp -o CMakeFiles\RyneGame.dir\main.s

# Object files for target RyneGame
RyneGame_OBJECTS = \
"CMakeFiles/RyneGame.dir/main.obj"

# External object files for target RyneGame
RyneGame_EXTERNAL_OBJECTS =

RyneGame.exe: CMakeFiles/RyneGame.dir/main.obj
RyneGame.exe: CMakeFiles/RyneGame.dir/build.make
RyneGame.exe: libmyGame.dll.a
RyneGame.exe: CMakeFiles/RyneGame.dir/linkLibs.rsp
RyneGame.exe: CMakeFiles/RyneGame.dir/objects1.rsp
RyneGame.exe: CMakeFiles/RyneGame.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\CLion\CLion_Repository\test4\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable RyneGame.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\RyneGame.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/RyneGame.dir/build: RyneGame.exe
.PHONY : CMakeFiles/RyneGame.dir/build

CMakeFiles/RyneGame.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\RyneGame.dir\cmake_clean.cmake
.PHONY : CMakeFiles/RyneGame.dir/clean

CMakeFiles/RyneGame.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\CLion\CLion_Repository\test4 D:\CLion\CLion_Repository\test4 D:\CLion\CLion_Repository\test4\cmake-build-debug D:\CLion\CLion_Repository\test4\cmake-build-debug D:\CLion\CLion_Repository\test4\cmake-build-debug\CMakeFiles\RyneGame.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/RyneGame.dir/depend

