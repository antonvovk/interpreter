cmake_minimum_required(VERSION 3.10)
project(interpreter)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)
include_directories(Expressions)

add_executable(interpreter
        Expressions/Assign.cpp
        Expressions/Assign.h
        Expressions/Binary.cpp
        Expressions/Binary.h
        Expressions/Call.cpp
        Expressions/Call.h
        Expressions/Get.cpp
        Expressions/Get.h
        Expressions/Grouping.cpp
        Expressions/Grouping.h
        Expressions/Literal.cpp
        Expressions/Literal.h
        Expressions/Logical.cpp
        Expressions/Logical.h
        Expressions/Set.cpp
        Expressions/Set.h
        Expressions/Super.cpp
        Expressions/Super.h
        Expressions/This.cpp
        Expressions/This.h
        Expressions/Unary.cpp
        Expressions/Unary.h
        Expressions/Variable.cpp
        Expressions/Variable.h
        Enum.h
        Expression.h
        Main.cpp
        Printer.cpp
        Printer.h
        Scanner.cpp
        Scanner.h
        Token.cpp
        Token.h
        Utils.h Parser.cpp Parser.h ParseError.h)
