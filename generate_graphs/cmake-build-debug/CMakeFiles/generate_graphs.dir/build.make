# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /snap/clion/70/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/70/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/amir/Documents/Algorithms/MST/generate_graphs

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/amir/Documents/Algorithms/MST/generate_graphs/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/generate_graphs.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/generate_graphs.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/generate_graphs.dir/flags.make

CMakeFiles/generate_graphs.dir/main.cpp.o: CMakeFiles/generate_graphs.dir/flags.make
CMakeFiles/generate_graphs.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/amir/Documents/Algorithms/MST/generate_graphs/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/generate_graphs.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/generate_graphs.dir/main.cpp.o -c /home/amir/Documents/Algorithms/MST/generate_graphs/main.cpp

CMakeFiles/generate_graphs.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/generate_graphs.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/amir/Documents/Algorithms/MST/generate_graphs/main.cpp > CMakeFiles/generate_graphs.dir/main.cpp.i

CMakeFiles/generate_graphs.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/generate_graphs.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/amir/Documents/Algorithms/MST/generate_graphs/main.cpp -o CMakeFiles/generate_graphs.dir/main.cpp.s

# Object files for target generate_graphs
generate_graphs_OBJECTS = \
"CMakeFiles/generate_graphs.dir/main.cpp.o"

# External object files for target generate_graphs
generate_graphs_EXTERNAL_OBJECTS =

generate_graphs: CMakeFiles/generate_graphs.dir/main.cpp.o
generate_graphs: CMakeFiles/generate_graphs.dir/build.make
generate_graphs: CMakeFiles/generate_graphs.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/amir/Documents/Algorithms/MST/generate_graphs/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable generate_graphs"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/generate_graphs.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/generate_graphs.dir/build: generate_graphs

.PHONY : CMakeFiles/generate_graphs.dir/build

CMakeFiles/generate_graphs.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/generate_graphs.dir/cmake_clean.cmake
.PHONY : CMakeFiles/generate_graphs.dir/clean

CMakeFiles/generate_graphs.dir/depend:
	cd /home/amir/Documents/Algorithms/MST/generate_graphs/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/amir/Documents/Algorithms/MST/generate_graphs /home/amir/Documents/Algorithms/MST/generate_graphs /home/amir/Documents/Algorithms/MST/generate_graphs/cmake-build-debug /home/amir/Documents/Algorithms/MST/generate_graphs/cmake-build-debug /home/amir/Documents/Algorithms/MST/generate_graphs/cmake-build-debug/CMakeFiles/generate_graphs.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/generate_graphs.dir/depend

