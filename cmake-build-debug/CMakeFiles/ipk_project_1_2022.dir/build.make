# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.21

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
CMAKE_COMMAND = /home/alex/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/213.6777.58/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/alex/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/213.6777.58/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/alex/CLionProjects/ipk-project-1-2022

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/alex/CLionProjects/ipk-project-1-2022/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ipk_project_1_2022.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/ipk_project_1_2022.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ipk_project_1_2022.dir/flags.make

CMakeFiles/ipk_project_1_2022.dir/main.c.o: CMakeFiles/ipk_project_1_2022.dir/flags.make
CMakeFiles/ipk_project_1_2022.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alex/CLionProjects/ipk-project-1-2022/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/ipk_project_1_2022.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ipk_project_1_2022.dir/main.c.o -c /home/alex/CLionProjects/ipk-project-1-2022/main.c

CMakeFiles/ipk_project_1_2022.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ipk_project_1_2022.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/alex/CLionProjects/ipk-project-1-2022/main.c > CMakeFiles/ipk_project_1_2022.dir/main.c.i

CMakeFiles/ipk_project_1_2022.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ipk_project_1_2022.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/alex/CLionProjects/ipk-project-1-2022/main.c -o CMakeFiles/ipk_project_1_2022.dir/main.c.s

CMakeFiles/ipk_project_1_2022.dir/functions.c.o: CMakeFiles/ipk_project_1_2022.dir/flags.make
CMakeFiles/ipk_project_1_2022.dir/functions.c.o: ../functions.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alex/CLionProjects/ipk-project-1-2022/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/ipk_project_1_2022.dir/functions.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ipk_project_1_2022.dir/functions.c.o -c /home/alex/CLionProjects/ipk-project-1-2022/functions.c

CMakeFiles/ipk_project_1_2022.dir/functions.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ipk_project_1_2022.dir/functions.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/alex/CLionProjects/ipk-project-1-2022/functions.c > CMakeFiles/ipk_project_1_2022.dir/functions.c.i

CMakeFiles/ipk_project_1_2022.dir/functions.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ipk_project_1_2022.dir/functions.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/alex/CLionProjects/ipk-project-1-2022/functions.c -o CMakeFiles/ipk_project_1_2022.dir/functions.c.s

# Object files for target ipk_project_1_2022
ipk_project_1_2022_OBJECTS = \
"CMakeFiles/ipk_project_1_2022.dir/main.c.o" \
"CMakeFiles/ipk_project_1_2022.dir/functions.c.o"

# External object files for target ipk_project_1_2022
ipk_project_1_2022_EXTERNAL_OBJECTS =

ipk_project_1_2022: CMakeFiles/ipk_project_1_2022.dir/main.c.o
ipk_project_1_2022: CMakeFiles/ipk_project_1_2022.dir/functions.c.o
ipk_project_1_2022: CMakeFiles/ipk_project_1_2022.dir/build.make
ipk_project_1_2022: CMakeFiles/ipk_project_1_2022.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/alex/CLionProjects/ipk-project-1-2022/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable ipk_project_1_2022"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ipk_project_1_2022.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ipk_project_1_2022.dir/build: ipk_project_1_2022
.PHONY : CMakeFiles/ipk_project_1_2022.dir/build

CMakeFiles/ipk_project_1_2022.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ipk_project_1_2022.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ipk_project_1_2022.dir/clean

CMakeFiles/ipk_project_1_2022.dir/depend:
	cd /home/alex/CLionProjects/ipk-project-1-2022/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/alex/CLionProjects/ipk-project-1-2022 /home/alex/CLionProjects/ipk-project-1-2022 /home/alex/CLionProjects/ipk-project-1-2022/cmake-build-debug /home/alex/CLionProjects/ipk-project-1-2022/cmake-build-debug /home/alex/CLionProjects/ipk-project-1-2022/cmake-build-debug/CMakeFiles/ipk_project_1_2022.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ipk_project_1_2022.dir/depend

