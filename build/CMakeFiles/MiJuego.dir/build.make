# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /home/fv/Escritorio/Workspace/TheEricsJourney

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/fv/Escritorio/Workspace/TheEricsJourney/build

# Include any dependencies generated for this target.
include CMakeFiles/MiJuego.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/MiJuego.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MiJuego.dir/flags.make

CMakeFiles/MiJuego.dir/main.cpp.o: CMakeFiles/MiJuego.dir/flags.make
CMakeFiles/MiJuego.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fv/Escritorio/Workspace/TheEricsJourney/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/MiJuego.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MiJuego.dir/main.cpp.o -c /home/fv/Escritorio/Workspace/TheEricsJourney/main.cpp

CMakeFiles/MiJuego.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MiJuego.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fv/Escritorio/Workspace/TheEricsJourney/main.cpp > CMakeFiles/MiJuego.dir/main.cpp.i

CMakeFiles/MiJuego.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MiJuego.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fv/Escritorio/Workspace/TheEricsJourney/main.cpp -o CMakeFiles/MiJuego.dir/main.cpp.s

CMakeFiles/MiJuego.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/MiJuego.dir/main.cpp.o.requires

CMakeFiles/MiJuego.dir/main.cpp.o.provides: CMakeFiles/MiJuego.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/MiJuego.dir/build.make CMakeFiles/MiJuego.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/MiJuego.dir/main.cpp.o.provides

CMakeFiles/MiJuego.dir/main.cpp.o.provides.build: CMakeFiles/MiJuego.dir/main.cpp.o


# Object files for target MiJuego
MiJuego_OBJECTS = \
"CMakeFiles/MiJuego.dir/main.cpp.o"

# External object files for target MiJuego
MiJuego_EXTERNAL_OBJECTS =

MiJuego: CMakeFiles/MiJuego.dir/main.cpp.o
MiJuego: CMakeFiles/MiJuego.dir/build.make
MiJuego: liblibModulos.a
MiJuego: /usr/lib/x86_64-linux-gnu/libsfml-system.so
MiJuego: /usr/lib/x86_64-linux-gnu/libsfml-window.so
MiJuego: /usr/lib/x86_64-linux-gnu/libsfml-graphics.so
MiJuego: /usr/lib/x86_64-linux-gnu/libsfml-network.so
MiJuego: /usr/lib/x86_64-linux-gnu/libsfml-audio.so
MiJuego: CMakeFiles/MiJuego.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/fv/Escritorio/Workspace/TheEricsJourney/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable MiJuego"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MiJuego.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MiJuego.dir/build: MiJuego

.PHONY : CMakeFiles/MiJuego.dir/build

CMakeFiles/MiJuego.dir/requires: CMakeFiles/MiJuego.dir/main.cpp.o.requires

.PHONY : CMakeFiles/MiJuego.dir/requires

CMakeFiles/MiJuego.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/MiJuego.dir/cmake_clean.cmake
.PHONY : CMakeFiles/MiJuego.dir/clean

CMakeFiles/MiJuego.dir/depend:
	cd /home/fv/Escritorio/Workspace/TheEricsJourney/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/fv/Escritorio/Workspace/TheEricsJourney /home/fv/Escritorio/Workspace/TheEricsJourney /home/fv/Escritorio/Workspace/TheEricsJourney/build /home/fv/Escritorio/Workspace/TheEricsJourney/build /home/fv/Escritorio/Workspace/TheEricsJourney/build/CMakeFiles/MiJuego.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/MiJuego.dir/depend

