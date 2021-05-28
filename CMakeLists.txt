# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.1...3.18 FATAL_ERROR)
project(monitor)


add_executable(app main.cpp handle_sigusr1.cpp)  
 
