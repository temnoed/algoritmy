# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.6

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files (x86)\JetBrains\CLion 2016.3.2\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files (x86)\JetBrains\CLion 2016.3.2\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\Coding\Ci\Lesson8

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\Coding\Ci\Lesson8\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Lesson8.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Lesson8.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Lesson8.dir/flags.make

CMakeFiles/Lesson8.dir/main.c.obj: CMakeFiles/Lesson8.dir/flags.make
CMakeFiles/Lesson8.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Coding\Ci\Lesson8\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Lesson8.dir/main.c.obj"
	C:\MinGW\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\Lesson8.dir\main.c.obj   -c D:\Coding\Ci\Lesson8\main.c

CMakeFiles/Lesson8.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Lesson8.dir/main.c.i"
	C:\MinGW\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\Coding\Ci\Lesson8\main.c > CMakeFiles\Lesson8.dir\main.c.i

CMakeFiles/Lesson8.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Lesson8.dir/main.c.s"
	C:\MinGW\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\Coding\Ci\Lesson8\main.c -o CMakeFiles\Lesson8.dir\main.c.s

CMakeFiles/Lesson8.dir/main.c.obj.requires:

.PHONY : CMakeFiles/Lesson8.dir/main.c.obj.requires

CMakeFiles/Lesson8.dir/main.c.obj.provides: CMakeFiles/Lesson8.dir/main.c.obj.requires
	$(MAKE) -f CMakeFiles\Lesson8.dir\build.make CMakeFiles/Lesson8.dir/main.c.obj.provides.build
.PHONY : CMakeFiles/Lesson8.dir/main.c.obj.provides

CMakeFiles/Lesson8.dir/main.c.obj.provides.build: CMakeFiles/Lesson8.dir/main.c.obj


# Object files for target Lesson8
Lesson8_OBJECTS = \
"CMakeFiles/Lesson8.dir/main.c.obj"

# External object files for target Lesson8
Lesson8_EXTERNAL_OBJECTS =

Lesson8.exe: CMakeFiles/Lesson8.dir/main.c.obj
Lesson8.exe: CMakeFiles/Lesson8.dir/build.make
Lesson8.exe: CMakeFiles/Lesson8.dir/linklibs.rsp
Lesson8.exe: CMakeFiles/Lesson8.dir/objects1.rsp
Lesson8.exe: CMakeFiles/Lesson8.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\Coding\Ci\Lesson8\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Lesson8.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Lesson8.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Lesson8.dir/build: Lesson8.exe

.PHONY : CMakeFiles/Lesson8.dir/build

CMakeFiles/Lesson8.dir/requires: CMakeFiles/Lesson8.dir/main.c.obj.requires

.PHONY : CMakeFiles/Lesson8.dir/requires

CMakeFiles/Lesson8.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Lesson8.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Lesson8.dir/clean

CMakeFiles/Lesson8.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Coding\Ci\Lesson8 D:\Coding\Ci\Lesson8 D:\Coding\Ci\Lesson8\cmake-build-debug D:\Coding\Ci\Lesson8\cmake-build-debug D:\Coding\Ci\Lesson8\cmake-build-debug\CMakeFiles\Lesson8.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Lesson8.dir/depend
