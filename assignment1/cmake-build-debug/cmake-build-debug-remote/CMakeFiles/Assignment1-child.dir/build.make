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
CMAKE_SOURCE_DIR = /home/testi/Documents/sovellusohjelmointi/assignment1/cmake-build-debug

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/testi/Documents/sovellusohjelmointi/assignment1/cmake-build-debug/cmake-build-debug-remote

# Include any dependencies generated for this target.
include CMakeFiles/Assignment1-child.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Assignment1-child.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Assignment1-child.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Assignment1-child.dir/flags.make

CMakeFiles/Assignment1-child.dir/execmain.c.o: CMakeFiles/Assignment1-child.dir/flags.make
CMakeFiles/Assignment1-child.dir/execmain.c.o: ../execmain.c
CMakeFiles/Assignment1-child.dir/execmain.c.o: CMakeFiles/Assignment1-child.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/testi/Documents/sovellusohjelmointi/assignment1/cmake-build-debug/cmake-build-debug-remote/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Assignment1-child.dir/execmain.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/Assignment1-child.dir/execmain.c.o -MF CMakeFiles/Assignment1-child.dir/execmain.c.o.d -o CMakeFiles/Assignment1-child.dir/execmain.c.o -c /home/testi/Documents/sovellusohjelmointi/assignment1/cmake-build-debug/execmain.c

CMakeFiles/Assignment1-child.dir/execmain.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Assignment1-child.dir/execmain.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/testi/Documents/sovellusohjelmointi/assignment1/cmake-build-debug/execmain.c > CMakeFiles/Assignment1-child.dir/execmain.c.i

CMakeFiles/Assignment1-child.dir/execmain.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Assignment1-child.dir/execmain.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/testi/Documents/sovellusohjelmointi/assignment1/cmake-build-debug/execmain.c -o CMakeFiles/Assignment1-child.dir/execmain.c.s

CMakeFiles/Assignment1-child.dir/morse.c.o: CMakeFiles/Assignment1-child.dir/flags.make
CMakeFiles/Assignment1-child.dir/morse.c.o: ../morse.c
CMakeFiles/Assignment1-child.dir/morse.c.o: CMakeFiles/Assignment1-child.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/testi/Documents/sovellusohjelmointi/assignment1/cmake-build-debug/cmake-build-debug-remote/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/Assignment1-child.dir/morse.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/Assignment1-child.dir/morse.c.o -MF CMakeFiles/Assignment1-child.dir/morse.c.o.d -o CMakeFiles/Assignment1-child.dir/morse.c.o -c /home/testi/Documents/sovellusohjelmointi/assignment1/cmake-build-debug/morse.c

CMakeFiles/Assignment1-child.dir/morse.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Assignment1-child.dir/morse.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/testi/Documents/sovellusohjelmointi/assignment1/cmake-build-debug/morse.c > CMakeFiles/Assignment1-child.dir/morse.c.i

CMakeFiles/Assignment1-child.dir/morse.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Assignment1-child.dir/morse.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/testi/Documents/sovellusohjelmointi/assignment1/cmake-build-debug/morse.c -o CMakeFiles/Assignment1-child.dir/morse.c.s

CMakeFiles/Assignment1-child.dir/logging.c.o: CMakeFiles/Assignment1-child.dir/flags.make
CMakeFiles/Assignment1-child.dir/logging.c.o: ../logging.c
CMakeFiles/Assignment1-child.dir/logging.c.o: CMakeFiles/Assignment1-child.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/testi/Documents/sovellusohjelmointi/assignment1/cmake-build-debug/cmake-build-debug-remote/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/Assignment1-child.dir/logging.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/Assignment1-child.dir/logging.c.o -MF CMakeFiles/Assignment1-child.dir/logging.c.o.d -o CMakeFiles/Assignment1-child.dir/logging.c.o -c /home/testi/Documents/sovellusohjelmointi/assignment1/cmake-build-debug/logging.c

CMakeFiles/Assignment1-child.dir/logging.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Assignment1-child.dir/logging.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/testi/Documents/sovellusohjelmointi/assignment1/cmake-build-debug/logging.c > CMakeFiles/Assignment1-child.dir/logging.c.i

CMakeFiles/Assignment1-child.dir/logging.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Assignment1-child.dir/logging.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/testi/Documents/sovellusohjelmointi/assignment1/cmake-build-debug/logging.c -o CMakeFiles/Assignment1-child.dir/logging.c.s

# Object files for target Assignment1-child
Assignment1__child_OBJECTS = \
"CMakeFiles/Assignment1-child.dir/execmain.c.o" \
"CMakeFiles/Assignment1-child.dir/morse.c.o" \
"CMakeFiles/Assignment1-child.dir/logging.c.o"

# External object files for target Assignment1-child
Assignment1__child_EXTERNAL_OBJECTS =

Assignment1-child: CMakeFiles/Assignment1-child.dir/execmain.c.o
Assignment1-child: CMakeFiles/Assignment1-child.dir/morse.c.o
Assignment1-child: CMakeFiles/Assignment1-child.dir/logging.c.o
Assignment1-child: CMakeFiles/Assignment1-child.dir/build.make
Assignment1-child: CMakeFiles/Assignment1-child.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/testi/Documents/sovellusohjelmointi/assignment1/cmake-build-debug/cmake-build-debug-remote/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable Assignment1-child"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Assignment1-child.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Assignment1-child.dir/build: Assignment1-child
.PHONY : CMakeFiles/Assignment1-child.dir/build

CMakeFiles/Assignment1-child.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Assignment1-child.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Assignment1-child.dir/clean

CMakeFiles/Assignment1-child.dir/depend:
	cd /home/testi/Documents/sovellusohjelmointi/assignment1/cmake-build-debug/cmake-build-debug-remote && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/testi/Documents/sovellusohjelmointi/assignment1/cmake-build-debug /home/testi/Documents/sovellusohjelmointi/assignment1/cmake-build-debug /home/testi/Documents/sovellusohjelmointi/assignment1/cmake-build-debug/cmake-build-debug-remote /home/testi/Documents/sovellusohjelmointi/assignment1/cmake-build-debug/cmake-build-debug-remote /home/testi/Documents/sovellusohjelmointi/assignment1/cmake-build-debug/cmake-build-debug-remote/CMakeFiles/Assignment1-child.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Assignment1-child.dir/depend

