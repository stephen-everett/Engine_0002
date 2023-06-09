# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.24

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:

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
CMAKE_SOURCE_DIR = /home/l0fi/Documents/SDL2/Engine_0002

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/l0fi/Documents/SDL2/Engine_0002

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/l0fi/Documents/SDL2/Engine_0002/CMakeFiles /home/l0fi/Documents/SDL2/Engine_0002//CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/l0fi/Documents/SDL2/Engine_0002/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named Main

# Build rule for target.
Main: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 Main
.PHONY : Main

# fast build rule for target.
Main/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Main.dir/build.make CMakeFiles/Main.dir/build
.PHONY : Main/fast

src/BusNode.o: src/BusNode.cpp.o
.PHONY : src/BusNode.o

# target to build an object file
src/BusNode.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Main.dir/build.make CMakeFiles/Main.dir/src/BusNode.cpp.o
.PHONY : src/BusNode.cpp.o

src/BusNode.i: src/BusNode.cpp.i
.PHONY : src/BusNode.i

# target to preprocess a source file
src/BusNode.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Main.dir/build.make CMakeFiles/Main.dir/src/BusNode.cpp.i
.PHONY : src/BusNode.cpp.i

src/BusNode.s: src/BusNode.cpp.s
.PHONY : src/BusNode.s

# target to generate assembly for a file
src/BusNode.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Main.dir/build.make CMakeFiles/Main.dir/src/BusNode.cpp.s
.PHONY : src/BusNode.cpp.s

src/Button.o: src/Button.cpp.o
.PHONY : src/Button.o

# target to build an object file
src/Button.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Main.dir/build.make CMakeFiles/Main.dir/src/Button.cpp.o
.PHONY : src/Button.cpp.o

src/Button.i: src/Button.cpp.i
.PHONY : src/Button.i

# target to preprocess a source file
src/Button.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Main.dir/build.make CMakeFiles/Main.dir/src/Button.cpp.i
.PHONY : src/Button.cpp.i

src/Button.s: src/Button.cpp.s
.PHONY : src/Button.s

# target to generate assembly for a file
src/Button.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Main.dir/build.make CMakeFiles/Main.dir/src/Button.cpp.s
.PHONY : src/Button.cpp.s

src/Entity.o: src/Entity.cpp.o
.PHONY : src/Entity.o

# target to build an object file
src/Entity.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Main.dir/build.make CMakeFiles/Main.dir/src/Entity.cpp.o
.PHONY : src/Entity.cpp.o

src/Entity.i: src/Entity.cpp.i
.PHONY : src/Entity.i

# target to preprocess a source file
src/Entity.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Main.dir/build.make CMakeFiles/Main.dir/src/Entity.cpp.i
.PHONY : src/Entity.cpp.i

src/Entity.s: src/Entity.cpp.s
.PHONY : src/Entity.s

# target to generate assembly for a file
src/Entity.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Main.dir/build.make CMakeFiles/Main.dir/src/Entity.cpp.s
.PHONY : src/Entity.cpp.s

src/EventBus.o: src/EventBus.cpp.o
.PHONY : src/EventBus.o

# target to build an object file
src/EventBus.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Main.dir/build.make CMakeFiles/Main.dir/src/EventBus.cpp.o
.PHONY : src/EventBus.cpp.o

src/EventBus.i: src/EventBus.cpp.i
.PHONY : src/EventBus.i

# target to preprocess a source file
src/EventBus.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Main.dir/build.make CMakeFiles/Main.dir/src/EventBus.cpp.i
.PHONY : src/EventBus.cpp.i

src/EventBus.s: src/EventBus.cpp.s
.PHONY : src/EventBus.s

# target to generate assembly for a file
src/EventBus.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Main.dir/build.make CMakeFiles/Main.dir/src/EventBus.cpp.s
.PHONY : src/EventBus.cpp.s

src/Main.o: src/Main.cpp.o
.PHONY : src/Main.o

# target to build an object file
src/Main.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Main.dir/build.make CMakeFiles/Main.dir/src/Main.cpp.o
.PHONY : src/Main.cpp.o

src/Main.i: src/Main.cpp.i
.PHONY : src/Main.i

# target to preprocess a source file
src/Main.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Main.dir/build.make CMakeFiles/Main.dir/src/Main.cpp.i
.PHONY : src/Main.cpp.i

src/Main.s: src/Main.cpp.s
.PHONY : src/Main.s

# target to generate assembly for a file
src/Main.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Main.dir/build.make CMakeFiles/Main.dir/src/Main.cpp.s
.PHONY : src/Main.cpp.s

src/MainMenu.o: src/MainMenu.cpp.o
.PHONY : src/MainMenu.o

# target to build an object file
src/MainMenu.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Main.dir/build.make CMakeFiles/Main.dir/src/MainMenu.cpp.o
.PHONY : src/MainMenu.cpp.o

src/MainMenu.i: src/MainMenu.cpp.i
.PHONY : src/MainMenu.i

# target to preprocess a source file
src/MainMenu.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Main.dir/build.make CMakeFiles/Main.dir/src/MainMenu.cpp.i
.PHONY : src/MainMenu.cpp.i

src/MainMenu.s: src/MainMenu.cpp.s
.PHONY : src/MainMenu.s

# target to generate assembly for a file
src/MainMenu.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Main.dir/build.make CMakeFiles/Main.dir/src/MainMenu.cpp.s
.PHONY : src/MainMenu.cpp.s

src/Map.o: src/Map.cpp.o
.PHONY : src/Map.o

# target to build an object file
src/Map.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Main.dir/build.make CMakeFiles/Main.dir/src/Map.cpp.o
.PHONY : src/Map.cpp.o

src/Map.i: src/Map.cpp.i
.PHONY : src/Map.i

# target to preprocess a source file
src/Map.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Main.dir/build.make CMakeFiles/Main.dir/src/Map.cpp.i
.PHONY : src/Map.cpp.i

src/Map.s: src/Map.cpp.s
.PHONY : src/Map.s

# target to generate assembly for a file
src/Map.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Main.dir/build.make CMakeFiles/Main.dir/src/Map.cpp.s
.PHONY : src/Map.cpp.s

src/Mouse.o: src/Mouse.cpp.o
.PHONY : src/Mouse.o

# target to build an object file
src/Mouse.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Main.dir/build.make CMakeFiles/Main.dir/src/Mouse.cpp.o
.PHONY : src/Mouse.cpp.o

src/Mouse.i: src/Mouse.cpp.i
.PHONY : src/Mouse.i

# target to preprocess a source file
src/Mouse.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Main.dir/build.make CMakeFiles/Main.dir/src/Mouse.cpp.i
.PHONY : src/Mouse.cpp.i

src/Mouse.s: src/Mouse.cpp.s
.PHONY : src/Mouse.s

# target to generate assembly for a file
src/Mouse.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Main.dir/build.make CMakeFiles/Main.dir/src/Mouse.cpp.s
.PHONY : src/Mouse.cpp.s

src/RenderSystem.o: src/RenderSystem.cpp.o
.PHONY : src/RenderSystem.o

# target to build an object file
src/RenderSystem.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Main.dir/build.make CMakeFiles/Main.dir/src/RenderSystem.cpp.o
.PHONY : src/RenderSystem.cpp.o

src/RenderSystem.i: src/RenderSystem.cpp.i
.PHONY : src/RenderSystem.i

# target to preprocess a source file
src/RenderSystem.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Main.dir/build.make CMakeFiles/Main.dir/src/RenderSystem.cpp.i
.PHONY : src/RenderSystem.cpp.i

src/RenderSystem.s: src/RenderSystem.cpp.s
.PHONY : src/RenderSystem.s

# target to generate assembly for a file
src/RenderSystem.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Main.dir/build.make CMakeFiles/Main.dir/src/RenderSystem.cpp.s
.PHONY : src/RenderSystem.cpp.s

src/ResourceManager.o: src/ResourceManager.cpp.o
.PHONY : src/ResourceManager.o

# target to build an object file
src/ResourceManager.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Main.dir/build.make CMakeFiles/Main.dir/src/ResourceManager.cpp.o
.PHONY : src/ResourceManager.cpp.o

src/ResourceManager.i: src/ResourceManager.cpp.i
.PHONY : src/ResourceManager.i

# target to preprocess a source file
src/ResourceManager.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Main.dir/build.make CMakeFiles/Main.dir/src/ResourceManager.cpp.i
.PHONY : src/ResourceManager.cpp.i

src/ResourceManager.s: src/ResourceManager.cpp.s
.PHONY : src/ResourceManager.s

# target to generate assembly for a file
src/ResourceManager.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Main.dir/build.make CMakeFiles/Main.dir/src/ResourceManager.cpp.s
.PHONY : src/ResourceManager.cpp.s

src/System.o: src/System.cpp.o
.PHONY : src/System.o

# target to build an object file
src/System.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Main.dir/build.make CMakeFiles/Main.dir/src/System.cpp.o
.PHONY : src/System.cpp.o

src/System.i: src/System.cpp.i
.PHONY : src/System.i

# target to preprocess a source file
src/System.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Main.dir/build.make CMakeFiles/Main.dir/src/System.cpp.i
.PHONY : src/System.cpp.i

src/System.s: src/System.cpp.s
.PHONY : src/System.s

# target to generate assembly for a file
src/System.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Main.dir/build.make CMakeFiles/Main.dir/src/System.cpp.s
.PHONY : src/System.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... Main"
	@echo "... src/BusNode.o"
	@echo "... src/BusNode.i"
	@echo "... src/BusNode.s"
	@echo "... src/Button.o"
	@echo "... src/Button.i"
	@echo "... src/Button.s"
	@echo "... src/Entity.o"
	@echo "... src/Entity.i"
	@echo "... src/Entity.s"
	@echo "... src/EventBus.o"
	@echo "... src/EventBus.i"
	@echo "... src/EventBus.s"
	@echo "... src/Main.o"
	@echo "... src/Main.i"
	@echo "... src/Main.s"
	@echo "... src/MainMenu.o"
	@echo "... src/MainMenu.i"
	@echo "... src/MainMenu.s"
	@echo "... src/Map.o"
	@echo "... src/Map.i"
	@echo "... src/Map.s"
	@echo "... src/Mouse.o"
	@echo "... src/Mouse.i"
	@echo "... src/Mouse.s"
	@echo "... src/RenderSystem.o"
	@echo "... src/RenderSystem.i"
	@echo "... src/RenderSystem.s"
	@echo "... src/ResourceManager.o"
	@echo "... src/ResourceManager.i"
	@echo "... src/ResourceManager.s"
	@echo "... src/System.o"
	@echo "... src/System.i"
	@echo "... src/System.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

