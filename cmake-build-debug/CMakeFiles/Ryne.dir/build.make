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
include CMakeFiles/Ryne.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Ryne.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Ryne.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Ryne.dir/flags.make

CMakeFiles/Ryne.dir/main.obj: CMakeFiles/Ryne.dir/flags.make
CMakeFiles/Ryne.dir/main.obj: D:/CLion/CLion_Repository/test4/main.cpp
CMakeFiles/Ryne.dir/main.obj: CMakeFiles/Ryne.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\CLion\CLion_Repository\test4\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Ryne.dir/main.obj"
	D:\CLion\CLion_body\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Ryne.dir/main.obj -MF CMakeFiles\Ryne.dir\main.obj.d -o CMakeFiles\Ryne.dir\main.obj -c D:\CLion\CLion_Repository\test4\main.cpp

CMakeFiles/Ryne.dir/main.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Ryne.dir/main.i"
	D:\CLion\CLion_body\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\CLion\CLion_Repository\test4\main.cpp > CMakeFiles\Ryne.dir\main.i

CMakeFiles/Ryne.dir/main.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Ryne.dir/main.s"
	D:\CLion\CLion_body\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\CLion\CLion_Repository\test4\main.cpp -o CMakeFiles\Ryne.dir\main.s

CMakeFiles/Ryne.dir/RoomState/Room.obj: CMakeFiles/Ryne.dir/flags.make
CMakeFiles/Ryne.dir/RoomState/Room.obj: D:/CLion/CLion_Repository/test4/RoomState/Room.cpp
CMakeFiles/Ryne.dir/RoomState/Room.obj: CMakeFiles/Ryne.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\CLion\CLion_Repository\test4\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Ryne.dir/RoomState/Room.obj"
	D:\CLion\CLion_body\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Ryne.dir/RoomState/Room.obj -MF CMakeFiles\Ryne.dir\RoomState\Room.obj.d -o CMakeFiles\Ryne.dir\RoomState\Room.obj -c D:\CLion\CLion_Repository\test4\RoomState\Room.cpp

CMakeFiles/Ryne.dir/RoomState/Room.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Ryne.dir/RoomState/Room.i"
	D:\CLion\CLion_body\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\CLion\CLion_Repository\test4\RoomState\Room.cpp > CMakeFiles\Ryne.dir\RoomState\Room.i

CMakeFiles/Ryne.dir/RoomState/Room.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Ryne.dir/RoomState/Room.s"
	D:\CLion\CLion_body\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\CLion\CLion_Repository\test4\RoomState\Room.cpp -o CMakeFiles\Ryne.dir\RoomState\Room.s

CMakeFiles/Ryne.dir/wordwrap.obj: CMakeFiles/Ryne.dir/flags.make
CMakeFiles/Ryne.dir/wordwrap.obj: D:/CLion/CLion_Repository/test4/wordwrap.cpp
CMakeFiles/Ryne.dir/wordwrap.obj: CMakeFiles/Ryne.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\CLion\CLion_Repository\test4\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Ryne.dir/wordwrap.obj"
	D:\CLion\CLion_body\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Ryne.dir/wordwrap.obj -MF CMakeFiles\Ryne.dir\wordwrap.obj.d -o CMakeFiles\Ryne.dir\wordwrap.obj -c D:\CLion\CLion_Repository\test4\wordwrap.cpp

CMakeFiles/Ryne.dir/wordwrap.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Ryne.dir/wordwrap.i"
	D:\CLion\CLion_body\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\CLion\CLion_Repository\test4\wordwrap.cpp > CMakeFiles\Ryne.dir\wordwrap.i

CMakeFiles/Ryne.dir/wordwrap.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Ryne.dir/wordwrap.s"
	D:\CLion\CLion_body\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\CLion\CLion_Repository\test4\wordwrap.cpp -o CMakeFiles\Ryne.dir\wordwrap.s

CMakeFiles/Ryne.dir/RoomState/State.obj: CMakeFiles/Ryne.dir/flags.make
CMakeFiles/Ryne.dir/RoomState/State.obj: D:/CLion/CLion_Repository/test4/RoomState/State.cpp
CMakeFiles/Ryne.dir/RoomState/State.obj: CMakeFiles/Ryne.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\CLion\CLion_Repository\test4\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Ryne.dir/RoomState/State.obj"
	D:\CLion\CLion_body\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Ryne.dir/RoomState/State.obj -MF CMakeFiles\Ryne.dir\RoomState\State.obj.d -o CMakeFiles\Ryne.dir\RoomState\State.obj -c D:\CLion\CLion_Repository\test4\RoomState\State.cpp

CMakeFiles/Ryne.dir/RoomState/State.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Ryne.dir/RoomState/State.i"
	D:\CLion\CLion_body\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\CLion\CLion_Repository\test4\RoomState\State.cpp > CMakeFiles\Ryne.dir\RoomState\State.i

CMakeFiles/Ryne.dir/RoomState/State.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Ryne.dir/RoomState/State.s"
	D:\CLion\CLion_body\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\CLion\CLion_Repository\test4\RoomState\State.cpp -o CMakeFiles\Ryne.dir\RoomState\State.s

CMakeFiles/Ryne.dir/Object/GameObject.obj: CMakeFiles/Ryne.dir/flags.make
CMakeFiles/Ryne.dir/Object/GameObject.obj: D:/CLion/CLion_Repository/test4/Object/GameObject.cpp
CMakeFiles/Ryne.dir/Object/GameObject.obj: CMakeFiles/Ryne.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\CLion\CLion_Repository\test4\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Ryne.dir/Object/GameObject.obj"
	D:\CLion\CLion_body\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Ryne.dir/Object/GameObject.obj -MF CMakeFiles\Ryne.dir\Object\GameObject.obj.d -o CMakeFiles\Ryne.dir\Object\GameObject.obj -c D:\CLion\CLion_Repository\test4\Object\GameObject.cpp

CMakeFiles/Ryne.dir/Object/GameObject.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Ryne.dir/Object/GameObject.i"
	D:\CLion\CLion_body\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\CLion\CLion_Repository\test4\Object\GameObject.cpp > CMakeFiles\Ryne.dir\Object\GameObject.i

CMakeFiles/Ryne.dir/Object/GameObject.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Ryne.dir/Object/GameObject.s"
	D:\CLion\CLion_body\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\CLion\CLion_Repository\test4\Object\GameObject.cpp -o CMakeFiles\Ryne.dir\Object\GameObject.s

CMakeFiles/Ryne.dir/Object/FoodObject.obj: CMakeFiles/Ryne.dir/flags.make
CMakeFiles/Ryne.dir/Object/FoodObject.obj: D:/CLion/CLion_Repository/test4/Object/FoodObject.cpp
CMakeFiles/Ryne.dir/Object/FoodObject.obj: CMakeFiles/Ryne.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\CLion\CLion_Repository\test4\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Ryne.dir/Object/FoodObject.obj"
	D:\CLion\CLion_body\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Ryne.dir/Object/FoodObject.obj -MF CMakeFiles\Ryne.dir\Object\FoodObject.obj.d -o CMakeFiles\Ryne.dir\Object\FoodObject.obj -c D:\CLion\CLion_Repository\test4\Object\FoodObject.cpp

CMakeFiles/Ryne.dir/Object/FoodObject.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Ryne.dir/Object/FoodObject.i"
	D:\CLion\CLion_body\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\CLion\CLion_Repository\test4\Object\FoodObject.cpp > CMakeFiles\Ryne.dir\Object\FoodObject.i

CMakeFiles/Ryne.dir/Object/FoodObject.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Ryne.dir/Object/FoodObject.s"
	D:\CLion\CLion_body\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\CLion\CLion_Repository\test4\Object\FoodObject.cpp -o CMakeFiles\Ryne.dir\Object\FoodObject.s

# Object files for target Ryne
Ryne_OBJECTS = \
"CMakeFiles/Ryne.dir/main.obj" \
"CMakeFiles/Ryne.dir/RoomState/Room.obj" \
"CMakeFiles/Ryne.dir/wordwrap.obj" \
"CMakeFiles/Ryne.dir/RoomState/State.obj" \
"CMakeFiles/Ryne.dir/Object/GameObject.obj" \
"CMakeFiles/Ryne.dir/Object/FoodObject.obj"

# External object files for target Ryne
Ryne_EXTERNAL_OBJECTS =

Ryne.exe: CMakeFiles/Ryne.dir/main.obj
Ryne.exe: CMakeFiles/Ryne.dir/RoomState/Room.obj
Ryne.exe: CMakeFiles/Ryne.dir/wordwrap.obj
Ryne.exe: CMakeFiles/Ryne.dir/RoomState/State.obj
Ryne.exe: CMakeFiles/Ryne.dir/Object/GameObject.obj
Ryne.exe: CMakeFiles/Ryne.dir/Object/FoodObject.obj
Ryne.exe: CMakeFiles/Ryne.dir/build.make
Ryne.exe: CMakeFiles/Ryne.dir/linkLibs.rsp
Ryne.exe: CMakeFiles/Ryne.dir/objects1.rsp
Ryne.exe: CMakeFiles/Ryne.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\CLion\CLion_Repository\test4\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable Ryne.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Ryne.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Ryne.dir/build: Ryne.exe
.PHONY : CMakeFiles/Ryne.dir/build

CMakeFiles/Ryne.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Ryne.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Ryne.dir/clean

CMakeFiles/Ryne.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\CLion\CLion_Repository\test4 D:\CLion\CLion_Repository\test4 D:\CLion\CLion_Repository\test4\cmake-build-debug D:\CLion\CLion_Repository\test4\cmake-build-debug D:\CLion\CLion_Repository\test4\cmake-build-debug\CMakeFiles\Ryne.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Ryne.dir/depend

