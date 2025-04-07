# Install script for directory: /mnt/d/cs_git_rep/goa-ev/src

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/mnt/d/cs_git_rep/goa-ev/build/lib/libgoa-ev.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/mnt/d/cs_git_rep/goa-ev/build/include/Acceptor.hpp;/mnt/d/cs_git_rep/goa-ev/build/include/Buffer.hpp;/mnt/d/cs_git_rep/goa-ev/build/include/Callbacks.hpp;/mnt/d/cs_git_rep/goa-ev/build/include/Channel.hpp;/mnt/d/cs_git_rep/goa-ev/build/include/Connector.hpp;/mnt/d/cs_git_rep/goa-ev/build/include/CountDownLatch.hpp;/mnt/d/cs_git_rep/goa-ev/build/include/EPollPoller.hpp;/mnt/d/cs_git_rep/goa-ev/build/include/EventLoop.hpp;/mnt/d/cs_git_rep/goa-ev/build/include/EventLoopThread.hpp;/mnt/d/cs_git_rep/goa-ev/build/include/InetAddress.hpp;/mnt/d/cs_git_rep/goa-ev/build/include/Logger.hpp;/mnt/d/cs_git_rep/goa-ev/build/include/noncopyable.hpp;/mnt/d/cs_git_rep/goa-ev/build/include/TcpClient.hpp;/mnt/d/cs_git_rep/goa-ev/build/include/TcpConnection.hpp;/mnt/d/cs_git_rep/goa-ev/build/include/TcpServer.hpp;/mnt/d/cs_git_rep/goa-ev/build/include/TcpServerSingle.hpp;/mnt/d/cs_git_rep/goa-ev/build/include/ThreadPool.hpp;/mnt/d/cs_git_rep/goa-ev/build/include/Timer.hpp;/mnt/d/cs_git_rep/goa-ev/build/include/TimerQueue.hpp;/mnt/d/cs_git_rep/goa-ev/build/include/Timestamp.hpp;/mnt/d/cs_git_rep/goa-ev/build/include/ThreadPool.hpp")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/mnt/d/cs_git_rep/goa-ev/build/include" TYPE FILE FILES
    "/mnt/d/cs_git_rep/goa-ev/src/Acceptor.hpp"
    "/mnt/d/cs_git_rep/goa-ev/src/Buffer.hpp"
    "/mnt/d/cs_git_rep/goa-ev/src/Callbacks.hpp"
    "/mnt/d/cs_git_rep/goa-ev/src/Channel.hpp"
    "/mnt/d/cs_git_rep/goa-ev/src/Connector.hpp"
    "/mnt/d/cs_git_rep/goa-ev/src/CountDownLatch.hpp"
    "/mnt/d/cs_git_rep/goa-ev/src/EPollPoller.hpp"
    "/mnt/d/cs_git_rep/goa-ev/src/EventLoop.hpp"
    "/mnt/d/cs_git_rep/goa-ev/src/EventLoopThread.hpp"
    "/mnt/d/cs_git_rep/goa-ev/src/InetAddress.hpp"
    "/mnt/d/cs_git_rep/goa-ev/src/Logger.hpp"
    "/mnt/d/cs_git_rep/goa-ev/src/noncopyable.hpp"
    "/mnt/d/cs_git_rep/goa-ev/src/TcpClient.hpp"
    "/mnt/d/cs_git_rep/goa-ev/src/TcpConnection.hpp"
    "/mnt/d/cs_git_rep/goa-ev/src/TcpServer.hpp"
    "/mnt/d/cs_git_rep/goa-ev/src/TcpServerSingle.hpp"
    "/mnt/d/cs_git_rep/goa-ev/src/ThreadPool.hpp"
    "/mnt/d/cs_git_rep/goa-ev/src/Timer.hpp"
    "/mnt/d/cs_git_rep/goa-ev/src/TimerQueue.hpp"
    "/mnt/d/cs_git_rep/goa-ev/src/Timestamp.hpp"
    "/mnt/d/cs_git_rep/goa-ev/src/ThreadPool.hpp"
    )
endif()

