# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/sc/MyProject/C:C++/DataStructure

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/sc/MyProject/C:C++/DataStructure/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/StaticLinkList.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/StaticLinkList.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/StaticLinkList.dir/flags.make

CMakeFiles/StaticLinkList.dir/一·线性表/静态链表.cpp.o: CMakeFiles/StaticLinkList.dir/flags.make
CMakeFiles/StaticLinkList.dir/一·线性表/静态链表.cpp.o: ../一·线性表/静态链表.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/sc/MyProject/C:C++/DataStructure/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/StaticLinkList.dir/一·线性表/静态链表.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/StaticLinkList.dir/一·线性表/静态链表.cpp.o -c /Users/sc/MyProject/C:C++/DataStructure/一·线性表/静态链表.cpp

CMakeFiles/StaticLinkList.dir/一·线性表/静态链表.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/StaticLinkList.dir/一·线性表/静态链表.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/sc/MyProject/C:C++/DataStructure/一·线性表/静态链表.cpp > CMakeFiles/StaticLinkList.dir/一·线性表/静态链表.cpp.i

CMakeFiles/StaticLinkList.dir/一·线性表/静态链表.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/StaticLinkList.dir/一·线性表/静态链表.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/sc/MyProject/C:C++/DataStructure/一·线性表/静态链表.cpp -o CMakeFiles/StaticLinkList.dir/一·线性表/静态链表.cpp.s

# Object files for target StaticLinkList
StaticLinkList_OBJECTS = \
"CMakeFiles/StaticLinkList.dir/一·线性表/静态链表.cpp.o"

# External object files for target StaticLinkList
StaticLinkList_EXTERNAL_OBJECTS =

StaticLinkList: CMakeFiles/StaticLinkList.dir/一·线性表/静态链表.cpp.o
StaticLinkList: CMakeFiles/StaticLinkList.dir/build.make
StaticLinkList: CMakeFiles/StaticLinkList.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/sc/MyProject/C:C++/DataStructure/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable StaticLinkList"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/StaticLinkList.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/StaticLinkList.dir/build: StaticLinkList
.PHONY : CMakeFiles/StaticLinkList.dir/build

CMakeFiles/StaticLinkList.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/StaticLinkList.dir/cmake_clean.cmake
.PHONY : CMakeFiles/StaticLinkList.dir/clean

CMakeFiles/StaticLinkList.dir/depend:
	cd /Users/sc/MyProject/C:C++/DataStructure/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/sc/MyProject/C:C++/DataStructure /Users/sc/MyProject/C:C++/DataStructure /Users/sc/MyProject/C:C++/DataStructure/cmake-build-debug /Users/sc/MyProject/C:C++/DataStructure/cmake-build-debug /Users/sc/MyProject/C:C++/DataStructure/cmake-build-debug/CMakeFiles/StaticLinkList.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/StaticLinkList.dir/depend
