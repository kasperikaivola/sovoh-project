# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/mnt/c/Users/kaspe/OneDrive - Aalto University/Aalto/Kurssit/ELEC-C7310 - Sovellusohjelmointi/Assignment1/Example"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/mnt/c/Users/kaspe/OneDrive - Aalto University/Aalto/Kurssit/ELEC-C7310 - Sovellusohjelmointi/Assignment1/Example/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Example1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Example1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Example1.dir/flags.make

CMakeFiles/Example1.dir/as1_mockup.c.o: CMakeFiles/Example1.dir/flags.make
CMakeFiles/Example1.dir/as1_mockup.c.o: ../as1_mockup.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/Users/kaspe/OneDrive - Aalto University/Aalto/Kurssit/ELEC-C7310 - Sovellusohjelmointi/Assignment1/Example/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Example1.dir/as1_mockup.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Example1.dir/as1_mockup.c.o   -c "/mnt/c/Users/kaspe/OneDrive - Aalto University/Aalto/Kurssit/ELEC-C7310 - Sovellusohjelmointi/Assignment1/Example/as1_mockup.c"

CMakeFiles/Example1.dir/as1_mockup.c.ind: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Example1.dir/as1_mockup.c.ind"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/mnt/c/Users/kaspe/OneDrive - Aalto University/Aalto/Kurssit/ELEC-C7310 - Sovellusohjelmointi/Assignment1/Example/as1_mockup.c" > CMakeFiles/Example1.dir/as1_mockup.c.ind

CMakeFiles/Example1.dir/as1_mockup.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Example1.dir/as1_mockup.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/mnt/c/Users/kaspe/OneDrive - Aalto University/Aalto/Kurssit/ELEC-C7310 - Sovellusohjelmointi/Assignment1/Example/as1_mockup.c" -o CMakeFiles/Example1.dir/as1_mockup.c.s

# Object files for target Example1
Example1_OBJECTS = \
"CMakeFiles/Example1.dir/as1_mockup.c.o"

# External object files for target Example1
Example1_EXTERNAL_OBJECTS =

Example1: CMakeFiles/Example1.dir/as1_mockup.c.o
Example1: CMakeFiles/Example1.dir/build.make
Example1: CMakeFiles/Example1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/mnt/c/Users/kaspe/OneDrive - Aalto University/Aalto/Kurssit/ELEC-C7310 - Sovellusohjelmointi/Assignment1/Example/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Example1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Example1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Example1.dir/build: Example1

.PHONY : CMakeFiles/Example1.dir/build

CMakeFiles/Example1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Example1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Example1.dir/clean

CMakeFiles/Example1.dir/depend:
	cd "/mnt/c/Users/kaspe/OneDrive - Aalto University/Aalto/Kurssit/ELEC-C7310 - Sovellusohjelmointi/Assignment1/Example/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/mnt/c/Users/kaspe/OneDrive - Aalto University/Aalto/Kurssit/ELEC-C7310 - Sovellusohjelmointi/Assignment1/Example" "/mnt/c/Users/kaspe/OneDrive - Aalto University/Aalto/Kurssit/ELEC-C7310 - Sovellusohjelmointi/Assignment1/Example" "/mnt/c/Users/kaspe/OneDrive - Aalto University/Aalto/Kurssit/ELEC-C7310 - Sovellusohjelmointi/Assignment1/Example/cmake-build-debug" "/mnt/c/Users/kaspe/OneDrive - Aalto University/Aalto/Kurssit/ELEC-C7310 - Sovellusohjelmointi/Assignment1/Example/cmake-build-debug" "/mnt/c/Users/kaspe/OneDrive - Aalto University/Aalto/Kurssit/ELEC-C7310 - Sovellusohjelmointi/Assignment1/Example/cmake-build-debug/CMakeFiles/Example1.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Example1.dir/depend

