# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.23

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/d/cs_git_rep/goa-ev

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/d/cs_git_rep/goa-ev/build

# Include any dependencies generated for this target.
include src/CMakeFiles/goa-ev.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/CMakeFiles/goa-ev.dir/compiler_depend.make

# Include the progress variables for this target.
include src/CMakeFiles/goa-ev.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/goa-ev.dir/flags.make

src/CMakeFiles/goa-ev.dir/EventLoop.cc.o: src/CMakeFiles/goa-ev.dir/flags.make
src/CMakeFiles/goa-ev.dir/EventLoop.cc.o: ../src/EventLoop.cc
src/CMakeFiles/goa-ev.dir/EventLoop.cc.o: src/CMakeFiles/goa-ev.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/cs_git_rep/goa-ev/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/goa-ev.dir/EventLoop.cc.o"
	cd /mnt/d/cs_git_rep/goa-ev/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/goa-ev.dir/EventLoop.cc.o -MF CMakeFiles/goa-ev.dir/EventLoop.cc.o.d -o CMakeFiles/goa-ev.dir/EventLoop.cc.o -c /mnt/d/cs_git_rep/goa-ev/src/EventLoop.cc

src/CMakeFiles/goa-ev.dir/EventLoop.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/goa-ev.dir/EventLoop.cc.i"
	cd /mnt/d/cs_git_rep/goa-ev/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/cs_git_rep/goa-ev/src/EventLoop.cc > CMakeFiles/goa-ev.dir/EventLoop.cc.i

src/CMakeFiles/goa-ev.dir/EventLoop.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/goa-ev.dir/EventLoop.cc.s"
	cd /mnt/d/cs_git_rep/goa-ev/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/cs_git_rep/goa-ev/src/EventLoop.cc -o CMakeFiles/goa-ev.dir/EventLoop.cc.s

src/CMakeFiles/goa-ev.dir/EPollPoller.cc.o: src/CMakeFiles/goa-ev.dir/flags.make
src/CMakeFiles/goa-ev.dir/EPollPoller.cc.o: ../src/EPollPoller.cc
src/CMakeFiles/goa-ev.dir/EPollPoller.cc.o: src/CMakeFiles/goa-ev.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/cs_git_rep/goa-ev/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/goa-ev.dir/EPollPoller.cc.o"
	cd /mnt/d/cs_git_rep/goa-ev/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/goa-ev.dir/EPollPoller.cc.o -MF CMakeFiles/goa-ev.dir/EPollPoller.cc.o.d -o CMakeFiles/goa-ev.dir/EPollPoller.cc.o -c /mnt/d/cs_git_rep/goa-ev/src/EPollPoller.cc

src/CMakeFiles/goa-ev.dir/EPollPoller.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/goa-ev.dir/EPollPoller.cc.i"
	cd /mnt/d/cs_git_rep/goa-ev/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/cs_git_rep/goa-ev/src/EPollPoller.cc > CMakeFiles/goa-ev.dir/EPollPoller.cc.i

src/CMakeFiles/goa-ev.dir/EPollPoller.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/goa-ev.dir/EPollPoller.cc.s"
	cd /mnt/d/cs_git_rep/goa-ev/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/cs_git_rep/goa-ev/src/EPollPoller.cc -o CMakeFiles/goa-ev.dir/EPollPoller.cc.s

src/CMakeFiles/goa-ev.dir/Channel.cc.o: src/CMakeFiles/goa-ev.dir/flags.make
src/CMakeFiles/goa-ev.dir/Channel.cc.o: ../src/Channel.cc
src/CMakeFiles/goa-ev.dir/Channel.cc.o: src/CMakeFiles/goa-ev.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/cs_git_rep/goa-ev/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/CMakeFiles/goa-ev.dir/Channel.cc.o"
	cd /mnt/d/cs_git_rep/goa-ev/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/goa-ev.dir/Channel.cc.o -MF CMakeFiles/goa-ev.dir/Channel.cc.o.d -o CMakeFiles/goa-ev.dir/Channel.cc.o -c /mnt/d/cs_git_rep/goa-ev/src/Channel.cc

src/CMakeFiles/goa-ev.dir/Channel.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/goa-ev.dir/Channel.cc.i"
	cd /mnt/d/cs_git_rep/goa-ev/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/cs_git_rep/goa-ev/src/Channel.cc > CMakeFiles/goa-ev.dir/Channel.cc.i

src/CMakeFiles/goa-ev.dir/Channel.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/goa-ev.dir/Channel.cc.s"
	cd /mnt/d/cs_git_rep/goa-ev/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/cs_git_rep/goa-ev/src/Channel.cc -o CMakeFiles/goa-ev.dir/Channel.cc.s

src/CMakeFiles/goa-ev.dir/Acceptor.cc.o: src/CMakeFiles/goa-ev.dir/flags.make
src/CMakeFiles/goa-ev.dir/Acceptor.cc.o: ../src/Acceptor.cc
src/CMakeFiles/goa-ev.dir/Acceptor.cc.o: src/CMakeFiles/goa-ev.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/cs_git_rep/goa-ev/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/CMakeFiles/goa-ev.dir/Acceptor.cc.o"
	cd /mnt/d/cs_git_rep/goa-ev/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/goa-ev.dir/Acceptor.cc.o -MF CMakeFiles/goa-ev.dir/Acceptor.cc.o.d -o CMakeFiles/goa-ev.dir/Acceptor.cc.o -c /mnt/d/cs_git_rep/goa-ev/src/Acceptor.cc

src/CMakeFiles/goa-ev.dir/Acceptor.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/goa-ev.dir/Acceptor.cc.i"
	cd /mnt/d/cs_git_rep/goa-ev/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/cs_git_rep/goa-ev/src/Acceptor.cc > CMakeFiles/goa-ev.dir/Acceptor.cc.i

src/CMakeFiles/goa-ev.dir/Acceptor.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/goa-ev.dir/Acceptor.cc.s"
	cd /mnt/d/cs_git_rep/goa-ev/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/cs_git_rep/goa-ev/src/Acceptor.cc -o CMakeFiles/goa-ev.dir/Acceptor.cc.s

src/CMakeFiles/goa-ev.dir/Buffer.cc.o: src/CMakeFiles/goa-ev.dir/flags.make
src/CMakeFiles/goa-ev.dir/Buffer.cc.o: ../src/Buffer.cc
src/CMakeFiles/goa-ev.dir/Buffer.cc.o: src/CMakeFiles/goa-ev.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/cs_git_rep/goa-ev/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object src/CMakeFiles/goa-ev.dir/Buffer.cc.o"
	cd /mnt/d/cs_git_rep/goa-ev/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/goa-ev.dir/Buffer.cc.o -MF CMakeFiles/goa-ev.dir/Buffer.cc.o.d -o CMakeFiles/goa-ev.dir/Buffer.cc.o -c /mnt/d/cs_git_rep/goa-ev/src/Buffer.cc

src/CMakeFiles/goa-ev.dir/Buffer.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/goa-ev.dir/Buffer.cc.i"
	cd /mnt/d/cs_git_rep/goa-ev/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/cs_git_rep/goa-ev/src/Buffer.cc > CMakeFiles/goa-ev.dir/Buffer.cc.i

src/CMakeFiles/goa-ev.dir/Buffer.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/goa-ev.dir/Buffer.cc.s"
	cd /mnt/d/cs_git_rep/goa-ev/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/cs_git_rep/goa-ev/src/Buffer.cc -o CMakeFiles/goa-ev.dir/Buffer.cc.s

src/CMakeFiles/goa-ev.dir/InetAddress.cc.o: src/CMakeFiles/goa-ev.dir/flags.make
src/CMakeFiles/goa-ev.dir/InetAddress.cc.o: ../src/InetAddress.cc
src/CMakeFiles/goa-ev.dir/InetAddress.cc.o: src/CMakeFiles/goa-ev.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/cs_git_rep/goa-ev/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object src/CMakeFiles/goa-ev.dir/InetAddress.cc.o"
	cd /mnt/d/cs_git_rep/goa-ev/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/goa-ev.dir/InetAddress.cc.o -MF CMakeFiles/goa-ev.dir/InetAddress.cc.o.d -o CMakeFiles/goa-ev.dir/InetAddress.cc.o -c /mnt/d/cs_git_rep/goa-ev/src/InetAddress.cc

src/CMakeFiles/goa-ev.dir/InetAddress.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/goa-ev.dir/InetAddress.cc.i"
	cd /mnt/d/cs_git_rep/goa-ev/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/cs_git_rep/goa-ev/src/InetAddress.cc > CMakeFiles/goa-ev.dir/InetAddress.cc.i

src/CMakeFiles/goa-ev.dir/InetAddress.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/goa-ev.dir/InetAddress.cc.s"
	cd /mnt/d/cs_git_rep/goa-ev/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/cs_git_rep/goa-ev/src/InetAddress.cc -o CMakeFiles/goa-ev.dir/InetAddress.cc.s

src/CMakeFiles/goa-ev.dir/TcpConnection.cc.o: src/CMakeFiles/goa-ev.dir/flags.make
src/CMakeFiles/goa-ev.dir/TcpConnection.cc.o: ../src/TcpConnection.cc
src/CMakeFiles/goa-ev.dir/TcpConnection.cc.o: src/CMakeFiles/goa-ev.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/cs_git_rep/goa-ev/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object src/CMakeFiles/goa-ev.dir/TcpConnection.cc.o"
	cd /mnt/d/cs_git_rep/goa-ev/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/goa-ev.dir/TcpConnection.cc.o -MF CMakeFiles/goa-ev.dir/TcpConnection.cc.o.d -o CMakeFiles/goa-ev.dir/TcpConnection.cc.o -c /mnt/d/cs_git_rep/goa-ev/src/TcpConnection.cc

src/CMakeFiles/goa-ev.dir/TcpConnection.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/goa-ev.dir/TcpConnection.cc.i"
	cd /mnt/d/cs_git_rep/goa-ev/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/cs_git_rep/goa-ev/src/TcpConnection.cc > CMakeFiles/goa-ev.dir/TcpConnection.cc.i

src/CMakeFiles/goa-ev.dir/TcpConnection.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/goa-ev.dir/TcpConnection.cc.s"
	cd /mnt/d/cs_git_rep/goa-ev/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/cs_git_rep/goa-ev/src/TcpConnection.cc -o CMakeFiles/goa-ev.dir/TcpConnection.cc.s

src/CMakeFiles/goa-ev.dir/TcpServerSingle.cc.o: src/CMakeFiles/goa-ev.dir/flags.make
src/CMakeFiles/goa-ev.dir/TcpServerSingle.cc.o: ../src/TcpServerSingle.cc
src/CMakeFiles/goa-ev.dir/TcpServerSingle.cc.o: src/CMakeFiles/goa-ev.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/cs_git_rep/goa-ev/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object src/CMakeFiles/goa-ev.dir/TcpServerSingle.cc.o"
	cd /mnt/d/cs_git_rep/goa-ev/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/goa-ev.dir/TcpServerSingle.cc.o -MF CMakeFiles/goa-ev.dir/TcpServerSingle.cc.o.d -o CMakeFiles/goa-ev.dir/TcpServerSingle.cc.o -c /mnt/d/cs_git_rep/goa-ev/src/TcpServerSingle.cc

src/CMakeFiles/goa-ev.dir/TcpServerSingle.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/goa-ev.dir/TcpServerSingle.cc.i"
	cd /mnt/d/cs_git_rep/goa-ev/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/cs_git_rep/goa-ev/src/TcpServerSingle.cc > CMakeFiles/goa-ev.dir/TcpServerSingle.cc.i

src/CMakeFiles/goa-ev.dir/TcpServerSingle.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/goa-ev.dir/TcpServerSingle.cc.s"
	cd /mnt/d/cs_git_rep/goa-ev/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/cs_git_rep/goa-ev/src/TcpServerSingle.cc -o CMakeFiles/goa-ev.dir/TcpServerSingle.cc.s

src/CMakeFiles/goa-ev.dir/TcpServer.cc.o: src/CMakeFiles/goa-ev.dir/flags.make
src/CMakeFiles/goa-ev.dir/TcpServer.cc.o: ../src/TcpServer.cc
src/CMakeFiles/goa-ev.dir/TcpServer.cc.o: src/CMakeFiles/goa-ev.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/cs_git_rep/goa-ev/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object src/CMakeFiles/goa-ev.dir/TcpServer.cc.o"
	cd /mnt/d/cs_git_rep/goa-ev/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/goa-ev.dir/TcpServer.cc.o -MF CMakeFiles/goa-ev.dir/TcpServer.cc.o.d -o CMakeFiles/goa-ev.dir/TcpServer.cc.o -c /mnt/d/cs_git_rep/goa-ev/src/TcpServer.cc

src/CMakeFiles/goa-ev.dir/TcpServer.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/goa-ev.dir/TcpServer.cc.i"
	cd /mnt/d/cs_git_rep/goa-ev/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/cs_git_rep/goa-ev/src/TcpServer.cc > CMakeFiles/goa-ev.dir/TcpServer.cc.i

src/CMakeFiles/goa-ev.dir/TcpServer.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/goa-ev.dir/TcpServer.cc.s"
	cd /mnt/d/cs_git_rep/goa-ev/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/cs_git_rep/goa-ev/src/TcpServer.cc -o CMakeFiles/goa-ev.dir/TcpServer.cc.s

src/CMakeFiles/goa-ev.dir/ThreadPool.cc.o: src/CMakeFiles/goa-ev.dir/flags.make
src/CMakeFiles/goa-ev.dir/ThreadPool.cc.o: ../src/ThreadPool.cc
src/CMakeFiles/goa-ev.dir/ThreadPool.cc.o: src/CMakeFiles/goa-ev.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/cs_git_rep/goa-ev/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object src/CMakeFiles/goa-ev.dir/ThreadPool.cc.o"
	cd /mnt/d/cs_git_rep/goa-ev/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/goa-ev.dir/ThreadPool.cc.o -MF CMakeFiles/goa-ev.dir/ThreadPool.cc.o.d -o CMakeFiles/goa-ev.dir/ThreadPool.cc.o -c /mnt/d/cs_git_rep/goa-ev/src/ThreadPool.cc

src/CMakeFiles/goa-ev.dir/ThreadPool.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/goa-ev.dir/ThreadPool.cc.i"
	cd /mnt/d/cs_git_rep/goa-ev/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/cs_git_rep/goa-ev/src/ThreadPool.cc > CMakeFiles/goa-ev.dir/ThreadPool.cc.i

src/CMakeFiles/goa-ev.dir/ThreadPool.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/goa-ev.dir/ThreadPool.cc.s"
	cd /mnt/d/cs_git_rep/goa-ev/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/cs_git_rep/goa-ev/src/ThreadPool.cc -o CMakeFiles/goa-ev.dir/ThreadPool.cc.s

src/CMakeFiles/goa-ev.dir/Connector.cc.o: src/CMakeFiles/goa-ev.dir/flags.make
src/CMakeFiles/goa-ev.dir/Connector.cc.o: ../src/Connector.cc
src/CMakeFiles/goa-ev.dir/Connector.cc.o: src/CMakeFiles/goa-ev.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/cs_git_rep/goa-ev/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object src/CMakeFiles/goa-ev.dir/Connector.cc.o"
	cd /mnt/d/cs_git_rep/goa-ev/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/goa-ev.dir/Connector.cc.o -MF CMakeFiles/goa-ev.dir/Connector.cc.o.d -o CMakeFiles/goa-ev.dir/Connector.cc.o -c /mnt/d/cs_git_rep/goa-ev/src/Connector.cc

src/CMakeFiles/goa-ev.dir/Connector.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/goa-ev.dir/Connector.cc.i"
	cd /mnt/d/cs_git_rep/goa-ev/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/cs_git_rep/goa-ev/src/Connector.cc > CMakeFiles/goa-ev.dir/Connector.cc.i

src/CMakeFiles/goa-ev.dir/Connector.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/goa-ev.dir/Connector.cc.s"
	cd /mnt/d/cs_git_rep/goa-ev/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/cs_git_rep/goa-ev/src/Connector.cc -o CMakeFiles/goa-ev.dir/Connector.cc.s

src/CMakeFiles/goa-ev.dir/TcpClient.cc.o: src/CMakeFiles/goa-ev.dir/flags.make
src/CMakeFiles/goa-ev.dir/TcpClient.cc.o: ../src/TcpClient.cc
src/CMakeFiles/goa-ev.dir/TcpClient.cc.o: src/CMakeFiles/goa-ev.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/cs_git_rep/goa-ev/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object src/CMakeFiles/goa-ev.dir/TcpClient.cc.o"
	cd /mnt/d/cs_git_rep/goa-ev/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/goa-ev.dir/TcpClient.cc.o -MF CMakeFiles/goa-ev.dir/TcpClient.cc.o.d -o CMakeFiles/goa-ev.dir/TcpClient.cc.o -c /mnt/d/cs_git_rep/goa-ev/src/TcpClient.cc

src/CMakeFiles/goa-ev.dir/TcpClient.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/goa-ev.dir/TcpClient.cc.i"
	cd /mnt/d/cs_git_rep/goa-ev/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/cs_git_rep/goa-ev/src/TcpClient.cc > CMakeFiles/goa-ev.dir/TcpClient.cc.i

src/CMakeFiles/goa-ev.dir/TcpClient.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/goa-ev.dir/TcpClient.cc.s"
	cd /mnt/d/cs_git_rep/goa-ev/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/cs_git_rep/goa-ev/src/TcpClient.cc -o CMakeFiles/goa-ev.dir/TcpClient.cc.s

src/CMakeFiles/goa-ev.dir/EventLoopThread.cc.o: src/CMakeFiles/goa-ev.dir/flags.make
src/CMakeFiles/goa-ev.dir/EventLoopThread.cc.o: ../src/EventLoopThread.cc
src/CMakeFiles/goa-ev.dir/EventLoopThread.cc.o: src/CMakeFiles/goa-ev.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/cs_git_rep/goa-ev/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object src/CMakeFiles/goa-ev.dir/EventLoopThread.cc.o"
	cd /mnt/d/cs_git_rep/goa-ev/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/goa-ev.dir/EventLoopThread.cc.o -MF CMakeFiles/goa-ev.dir/EventLoopThread.cc.o.d -o CMakeFiles/goa-ev.dir/EventLoopThread.cc.o -c /mnt/d/cs_git_rep/goa-ev/src/EventLoopThread.cc

src/CMakeFiles/goa-ev.dir/EventLoopThread.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/goa-ev.dir/EventLoopThread.cc.i"
	cd /mnt/d/cs_git_rep/goa-ev/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/cs_git_rep/goa-ev/src/EventLoopThread.cc > CMakeFiles/goa-ev.dir/EventLoopThread.cc.i

src/CMakeFiles/goa-ev.dir/EventLoopThread.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/goa-ev.dir/EventLoopThread.cc.s"
	cd /mnt/d/cs_git_rep/goa-ev/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/cs_git_rep/goa-ev/src/EventLoopThread.cc -o CMakeFiles/goa-ev.dir/EventLoopThread.cc.s

src/CMakeFiles/goa-ev.dir/TimerQueue.cc.o: src/CMakeFiles/goa-ev.dir/flags.make
src/CMakeFiles/goa-ev.dir/TimerQueue.cc.o: ../src/TimerQueue.cc
src/CMakeFiles/goa-ev.dir/TimerQueue.cc.o: src/CMakeFiles/goa-ev.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/cs_git_rep/goa-ev/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object src/CMakeFiles/goa-ev.dir/TimerQueue.cc.o"
	cd /mnt/d/cs_git_rep/goa-ev/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/goa-ev.dir/TimerQueue.cc.o -MF CMakeFiles/goa-ev.dir/TimerQueue.cc.o.d -o CMakeFiles/goa-ev.dir/TimerQueue.cc.o -c /mnt/d/cs_git_rep/goa-ev/src/TimerQueue.cc

src/CMakeFiles/goa-ev.dir/TimerQueue.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/goa-ev.dir/TimerQueue.cc.i"
	cd /mnt/d/cs_git_rep/goa-ev/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/cs_git_rep/goa-ev/src/TimerQueue.cc > CMakeFiles/goa-ev.dir/TimerQueue.cc.i

src/CMakeFiles/goa-ev.dir/TimerQueue.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/goa-ev.dir/TimerQueue.cc.s"
	cd /mnt/d/cs_git_rep/goa-ev/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/cs_git_rep/goa-ev/src/TimerQueue.cc -o CMakeFiles/goa-ev.dir/TimerQueue.cc.s

# Object files for target goa-ev
goa__ev_OBJECTS = \
"CMakeFiles/goa-ev.dir/EventLoop.cc.o" \
"CMakeFiles/goa-ev.dir/EPollPoller.cc.o" \
"CMakeFiles/goa-ev.dir/Channel.cc.o" \
"CMakeFiles/goa-ev.dir/Acceptor.cc.o" \
"CMakeFiles/goa-ev.dir/Buffer.cc.o" \
"CMakeFiles/goa-ev.dir/InetAddress.cc.o" \
"CMakeFiles/goa-ev.dir/TcpConnection.cc.o" \
"CMakeFiles/goa-ev.dir/TcpServerSingle.cc.o" \
"CMakeFiles/goa-ev.dir/TcpServer.cc.o" \
"CMakeFiles/goa-ev.dir/ThreadPool.cc.o" \
"CMakeFiles/goa-ev.dir/Connector.cc.o" \
"CMakeFiles/goa-ev.dir/TcpClient.cc.o" \
"CMakeFiles/goa-ev.dir/EventLoopThread.cc.o" \
"CMakeFiles/goa-ev.dir/TimerQueue.cc.o"

# External object files for target goa-ev
goa__ev_EXTERNAL_OBJECTS =

lib/libgoa-ev.a: src/CMakeFiles/goa-ev.dir/EventLoop.cc.o
lib/libgoa-ev.a: src/CMakeFiles/goa-ev.dir/EPollPoller.cc.o
lib/libgoa-ev.a: src/CMakeFiles/goa-ev.dir/Channel.cc.o
lib/libgoa-ev.a: src/CMakeFiles/goa-ev.dir/Acceptor.cc.o
lib/libgoa-ev.a: src/CMakeFiles/goa-ev.dir/Buffer.cc.o
lib/libgoa-ev.a: src/CMakeFiles/goa-ev.dir/InetAddress.cc.o
lib/libgoa-ev.a: src/CMakeFiles/goa-ev.dir/TcpConnection.cc.o
lib/libgoa-ev.a: src/CMakeFiles/goa-ev.dir/TcpServerSingle.cc.o
lib/libgoa-ev.a: src/CMakeFiles/goa-ev.dir/TcpServer.cc.o
lib/libgoa-ev.a: src/CMakeFiles/goa-ev.dir/ThreadPool.cc.o
lib/libgoa-ev.a: src/CMakeFiles/goa-ev.dir/Connector.cc.o
lib/libgoa-ev.a: src/CMakeFiles/goa-ev.dir/TcpClient.cc.o
lib/libgoa-ev.a: src/CMakeFiles/goa-ev.dir/EventLoopThread.cc.o
lib/libgoa-ev.a: src/CMakeFiles/goa-ev.dir/TimerQueue.cc.o
lib/libgoa-ev.a: src/CMakeFiles/goa-ev.dir/build.make
lib/libgoa-ev.a: src/CMakeFiles/goa-ev.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/d/cs_git_rep/goa-ev/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Linking CXX static library ../lib/libgoa-ev.a"
	cd /mnt/d/cs_git_rep/goa-ev/build/src && $(CMAKE_COMMAND) -P CMakeFiles/goa-ev.dir/cmake_clean_target.cmake
	cd /mnt/d/cs_git_rep/goa-ev/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/goa-ev.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/goa-ev.dir/build: lib/libgoa-ev.a
.PHONY : src/CMakeFiles/goa-ev.dir/build

src/CMakeFiles/goa-ev.dir/clean:
	cd /mnt/d/cs_git_rep/goa-ev/build/src && $(CMAKE_COMMAND) -P CMakeFiles/goa-ev.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/goa-ev.dir/clean

src/CMakeFiles/goa-ev.dir/depend:
	cd /mnt/d/cs_git_rep/goa-ev/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/d/cs_git_rep/goa-ev /mnt/d/cs_git_rep/goa-ev/src /mnt/d/cs_git_rep/goa-ev/build /mnt/d/cs_git_rep/goa-ev/build/src /mnt/d/cs_git_rep/goa-ev/build/src/CMakeFiles/goa-ev.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/goa-ev.dir/depend

