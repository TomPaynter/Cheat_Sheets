# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.4

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.4.2/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.4.2/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/Emmet/Projects/Cheat_Sheets/C++/ProtoBuf

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/Emmet/Projects/Cheat_Sheets/C++/ProtoBuf/build

# Include any dependencies generated for this target.
include CMakeFiles/proto.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/proto.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/proto.dir/flags.make

partbook.pb.cc: ../partbook.proto
partbook.pb.cc: /usr/local/bin/protoc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/Emmet/Projects/Cheat_Sheets/C++/ProtoBuf/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Running C++ protocol buffer compiler on partbook.proto"
	/usr/local/bin/protoc --cpp_out /Users/Emmet/Projects/Cheat_Sheets/C++/ProtoBuf/build -I /Users/Emmet/Projects/Cheat_Sheets/C++/ProtoBuf /Users/Emmet/Projects/Cheat_Sheets/C++/ProtoBuf/partbook.proto

partbook.pb.h: partbook.pb.cc
	@$(CMAKE_COMMAND) -E touch_nocreate partbook.pb.h

CMakeFiles/proto.dir/partbook.pb.cc.o: CMakeFiles/proto.dir/flags.make
CMakeFiles/proto.dir/partbook.pb.cc.o: partbook.pb.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Emmet/Projects/Cheat_Sheets/C++/ProtoBuf/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/proto.dir/partbook.pb.cc.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/proto.dir/partbook.pb.cc.o -c /Users/Emmet/Projects/Cheat_Sheets/C++/ProtoBuf/build/partbook.pb.cc

CMakeFiles/proto.dir/partbook.pb.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/proto.dir/partbook.pb.cc.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/Emmet/Projects/Cheat_Sheets/C++/ProtoBuf/build/partbook.pb.cc > CMakeFiles/proto.dir/partbook.pb.cc.i

CMakeFiles/proto.dir/partbook.pb.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/proto.dir/partbook.pb.cc.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/Emmet/Projects/Cheat_Sheets/C++/ProtoBuf/build/partbook.pb.cc -o CMakeFiles/proto.dir/partbook.pb.cc.s

CMakeFiles/proto.dir/partbook.pb.cc.o.requires:

.PHONY : CMakeFiles/proto.dir/partbook.pb.cc.o.requires

CMakeFiles/proto.dir/partbook.pb.cc.o.provides: CMakeFiles/proto.dir/partbook.pb.cc.o.requires
	$(MAKE) -f CMakeFiles/proto.dir/build.make CMakeFiles/proto.dir/partbook.pb.cc.o.provides.build
.PHONY : CMakeFiles/proto.dir/partbook.pb.cc.o.provides

CMakeFiles/proto.dir/partbook.pb.cc.o.provides.build: CMakeFiles/proto.dir/partbook.pb.cc.o


# Object files for target proto
proto_OBJECTS = \
"CMakeFiles/proto.dir/partbook.pb.cc.o"

# External object files for target proto
proto_EXTERNAL_OBJECTS =

libproto.a: CMakeFiles/proto.dir/partbook.pb.cc.o
libproto.a: CMakeFiles/proto.dir/build.make
libproto.a: CMakeFiles/proto.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/Emmet/Projects/Cheat_Sheets/C++/ProtoBuf/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library libproto.a"
	$(CMAKE_COMMAND) -P CMakeFiles/proto.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/proto.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/proto.dir/build: libproto.a

.PHONY : CMakeFiles/proto.dir/build

CMakeFiles/proto.dir/requires: CMakeFiles/proto.dir/partbook.pb.cc.o.requires

.PHONY : CMakeFiles/proto.dir/requires

CMakeFiles/proto.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/proto.dir/cmake_clean.cmake
.PHONY : CMakeFiles/proto.dir/clean

CMakeFiles/proto.dir/depend: partbook.pb.cc
CMakeFiles/proto.dir/depend: partbook.pb.h
	cd /Users/Emmet/Projects/Cheat_Sheets/C++/ProtoBuf/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/Emmet/Projects/Cheat_Sheets/C++/ProtoBuf /Users/Emmet/Projects/Cheat_Sheets/C++/ProtoBuf /Users/Emmet/Projects/Cheat_Sheets/C++/ProtoBuf/build /Users/Emmet/Projects/Cheat_Sheets/C++/ProtoBuf/build /Users/Emmet/Projects/Cheat_Sheets/C++/ProtoBuf/build/CMakeFiles/proto.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/proto.dir/depend
