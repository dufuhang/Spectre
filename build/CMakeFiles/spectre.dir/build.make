# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Produce verbose output by default.
VERBOSE = 1

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/dufuhang/Spectre

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/dufuhang/Spectre/build

# Include any dependencies generated for this target.
include CMakeFiles/spectre.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/spectre.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/spectre.dir/flags.make

CMakeFiles/spectre.dir/spectre/log.cc.o: CMakeFiles/spectre.dir/flags.make
CMakeFiles/spectre.dir/spectre/log.cc.o: ../spectre/log.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dufuhang/Spectre/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/spectre.dir/spectre/log.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/spectre.dir/spectre/log.cc.o -c /home/dufuhang/Spectre/spectre/log.cc

CMakeFiles/spectre.dir/spectre/log.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/spectre.dir/spectre/log.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dufuhang/Spectre/spectre/log.cc > CMakeFiles/spectre.dir/spectre/log.cc.i

CMakeFiles/spectre.dir/spectre/log.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/spectre.dir/spectre/log.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dufuhang/Spectre/spectre/log.cc -o CMakeFiles/spectre.dir/spectre/log.cc.s

CMakeFiles/spectre.dir/spectre/log.cc.o.requires:

.PHONY : CMakeFiles/spectre.dir/spectre/log.cc.o.requires

CMakeFiles/spectre.dir/spectre/log.cc.o.provides: CMakeFiles/spectre.dir/spectre/log.cc.o.requires
	$(MAKE) -f CMakeFiles/spectre.dir/build.make CMakeFiles/spectre.dir/spectre/log.cc.o.provides.build
.PHONY : CMakeFiles/spectre.dir/spectre/log.cc.o.provides

CMakeFiles/spectre.dir/spectre/log.cc.o.provides.build: CMakeFiles/spectre.dir/spectre/log.cc.o


CMakeFiles/spectre.dir/spectre/util.cc.o: CMakeFiles/spectre.dir/flags.make
CMakeFiles/spectre.dir/spectre/util.cc.o: ../spectre/util.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dufuhang/Spectre/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/spectre.dir/spectre/util.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/spectre.dir/spectre/util.cc.o -c /home/dufuhang/Spectre/spectre/util.cc

CMakeFiles/spectre.dir/spectre/util.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/spectre.dir/spectre/util.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dufuhang/Spectre/spectre/util.cc > CMakeFiles/spectre.dir/spectre/util.cc.i

CMakeFiles/spectre.dir/spectre/util.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/spectre.dir/spectre/util.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dufuhang/Spectre/spectre/util.cc -o CMakeFiles/spectre.dir/spectre/util.cc.s

CMakeFiles/spectre.dir/spectre/util.cc.o.requires:

.PHONY : CMakeFiles/spectre.dir/spectre/util.cc.o.requires

CMakeFiles/spectre.dir/spectre/util.cc.o.provides: CMakeFiles/spectre.dir/spectre/util.cc.o.requires
	$(MAKE) -f CMakeFiles/spectre.dir/build.make CMakeFiles/spectre.dir/spectre/util.cc.o.provides.build
.PHONY : CMakeFiles/spectre.dir/spectre/util.cc.o.provides

CMakeFiles/spectre.dir/spectre/util.cc.o.provides.build: CMakeFiles/spectre.dir/spectre/util.cc.o


# Object files for target spectre
spectre_OBJECTS = \
"CMakeFiles/spectre.dir/spectre/log.cc.o" \
"CMakeFiles/spectre.dir/spectre/util.cc.o"

# External object files for target spectre
spectre_EXTERNAL_OBJECTS =

../lib/libspectre.so: CMakeFiles/spectre.dir/spectre/log.cc.o
../lib/libspectre.so: CMakeFiles/spectre.dir/spectre/util.cc.o
../lib/libspectre.so: CMakeFiles/spectre.dir/build.make
../lib/libspectre.so: CMakeFiles/spectre.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/dufuhang/Spectre/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX shared library ../lib/libspectre.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/spectre.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/spectre.dir/build: ../lib/libspectre.so

.PHONY : CMakeFiles/spectre.dir/build

CMakeFiles/spectre.dir/requires: CMakeFiles/spectre.dir/spectre/log.cc.o.requires
CMakeFiles/spectre.dir/requires: CMakeFiles/spectre.dir/spectre/util.cc.o.requires

.PHONY : CMakeFiles/spectre.dir/requires

CMakeFiles/spectre.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/spectre.dir/cmake_clean.cmake
.PHONY : CMakeFiles/spectre.dir/clean

CMakeFiles/spectre.dir/depend:
	cd /home/dufuhang/Spectre/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dufuhang/Spectre /home/dufuhang/Spectre /home/dufuhang/Spectre/build /home/dufuhang/Spectre/build /home/dufuhang/Spectre/build/CMakeFiles/spectre.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/spectre.dir/depend

