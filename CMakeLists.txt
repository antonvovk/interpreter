cmake_minimum_required(VERSION 3.13)
project(Interpreter)

set(CMAKE_CXX_STANDARD 17)

add_executable(Interpreter Main.cpp Utils.h Token.cpp Token.h Enum.h Scanner.cpp Scanner.h Expression.h Printer.cpp Printer.h Expressions/Assign.cpp Expressions/Assign.h Expressions/Binary.cpp Expressions/Binary.h Expressions/Call.cpp Expressions/Call.h Expressions/Get.cpp Expressions/Get.h Expressions/Grouping.cpp Expressions/Grouping.h Expressions/Literal.cpp Expressions/Literal.h Expressions/Logical.cpp Expressions/Logical.h Expressions/Set.cpp Expressions/Set.h Expressions/Super.cpp Expressions/Super.h Expressions/This.cpp Expressions/This.h Expressions/Unary.cpp Expressions/Unary.h Expressions/Variable.cpp Expressions/Variable.h)