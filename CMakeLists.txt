cmake_minimum_required(VERSION 3.13)
project(Interpreter)

set(CMAKE_CXX_STANDARD 17)

add_executable(Interpreter Main.cpp Utils.h Token.cpp Token.h Enum.h Scanner.cpp Scanner.h)