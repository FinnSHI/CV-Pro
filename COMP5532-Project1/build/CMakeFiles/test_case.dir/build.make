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
CMAKE_COMMAND = /Applications/CMake.app/Contents/bin/cmake

# The command to remove a file.
RM = /Applications/CMake.app/Contents/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/qihuazhou/Desktop/学术科研组/郭老师POLYU/PolyU课程/TA_COMP5523_Computer_Vision/mini-project/project1/COMP5532-Project1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/qihuazhou/Desktop/学术科研组/郭老师POLYU/PolyU课程/TA_COMP5523_Computer_Vision/mini-project/project1/COMP5532-Project1/build

# Include any dependencies generated for this target.
include CMakeFiles/test_case.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/test_case.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/test_case.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test_case.dir/flags.make

CMakeFiles/test_case.dir/src/test/test_case.cpp.o: CMakeFiles/test_case.dir/flags.make
CMakeFiles/test_case.dir/src/test/test_case.cpp.o: ../src/test/test_case.cpp
CMakeFiles/test_case.dir/src/test/test_case.cpp.o: CMakeFiles/test_case.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/qihuazhou/Desktop/学术科研组/郭老师POLYU/PolyU课程/TA_COMP5523_Computer_Vision/mini-project/project1/COMP5532-Project1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/test_case.dir/src/test/test_case.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/test_case.dir/src/test/test_case.cpp.o -MF CMakeFiles/test_case.dir/src/test/test_case.cpp.o.d -o CMakeFiles/test_case.dir/src/test/test_case.cpp.o -c /Users/qihuazhou/Desktop/学术科研组/郭老师POLYU/PolyU课程/TA_COMP5523_Computer_Vision/mini-project/project1/COMP5532-Project1/src/test/test_case.cpp

CMakeFiles/test_case.dir/src/test/test_case.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_case.dir/src/test/test_case.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/qihuazhou/Desktop/学术科研组/郭老师POLYU/PolyU课程/TA_COMP5523_Computer_Vision/mini-project/project1/COMP5532-Project1/src/test/test_case.cpp > CMakeFiles/test_case.dir/src/test/test_case.cpp.i

CMakeFiles/test_case.dir/src/test/test_case.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_case.dir/src/test/test_case.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/qihuazhou/Desktop/学术科研组/郭老师POLYU/PolyU课程/TA_COMP5523_Computer_Vision/mini-project/project1/COMP5532-Project1/src/test/test_case.cpp -o CMakeFiles/test_case.dir/src/test/test_case.cpp.s

# Object files for target test_case
test_case_OBJECTS = \
"CMakeFiles/test_case.dir/src/test/test_case.cpp.o"

# External object files for target test_case
test_case_EXTERNAL_OBJECTS =

../test_case: CMakeFiles/test_case.dir/src/test/test_case.cpp.o
../test_case: CMakeFiles/test_case.dir/build.make
../test_case: libuwimg++.dylib
../test_case: CMakeFiles/test_case.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/qihuazhou/Desktop/学术科研组/郭老师POLYU/PolyU课程/TA_COMP5523_Computer_Vision/mini-project/project1/COMP5532-Project1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../test_case"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_case.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test_case.dir/build: ../test_case
.PHONY : CMakeFiles/test_case.dir/build

CMakeFiles/test_case.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test_case.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test_case.dir/clean

CMakeFiles/test_case.dir/depend:
	cd /Users/qihuazhou/Desktop/学术科研组/郭老师POLYU/PolyU课程/TA_COMP5523_Computer_Vision/mini-project/project1/COMP5532-Project1/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/qihuazhou/Desktop/学术科研组/郭老师POLYU/PolyU课程/TA_COMP5523_Computer_Vision/mini-project/project1/COMP5532-Project1 /Users/qihuazhou/Desktop/学术科研组/郭老师POLYU/PolyU课程/TA_COMP5523_Computer_Vision/mini-project/project1/COMP5532-Project1 /Users/qihuazhou/Desktop/学术科研组/郭老师POLYU/PolyU课程/TA_COMP5523_Computer_Vision/mini-project/project1/COMP5532-Project1/build /Users/qihuazhou/Desktop/学术科研组/郭老师POLYU/PolyU课程/TA_COMP5523_Computer_Vision/mini-project/project1/COMP5532-Project1/build /Users/qihuazhou/Desktop/学术科研组/郭老师POLYU/PolyU课程/TA_COMP5523_Computer_Vision/mini-project/project1/COMP5532-Project1/build/CMakeFiles/test_case.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/test_case.dir/depend
