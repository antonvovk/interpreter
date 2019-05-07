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
        Expressions/Grouping.cpp
        Expressions/Grouping.h
        Expressions/Literal.cpp
        Expressions/Literal.h
        Expressions/Logical.cpp
        Expressions/Logical.h
        Expressions/Unary.cpp
        Expressions/Unary.h
        Expressions/Variable.cpp
        Expressions/Variable.h
        Enum.h
        Expression.h
        Main.cpp
        Scanner.cpp
        Scanner.h
        Token.cpp
        Token.h
        Utils.h Parser.cpp Parser.h ParseError.h Interpreter.cpp Interpreter.h RuntimeError.h Utils.cpp Statement.h Statements/Block.cpp Statements/Block.h Statements/ExpressionStmnt.cpp Statements/ExpressionStmnt.h Statements/If.cpp Statements/If.h Statements/Print.cpp Statements/Print.h Statements/Var.cpp Statements/Var.h Statements/While.cpp Statements/While.h Environment.cpp Environment.h Statements/Move.cpp Statements/Move.h Statements/Copy.cpp Statements/Copy.h Statements/Remove.cpp Statements/Remove.h Statements/Find.cpp Statements/Find.h Statements/FindSame.cpp Statements/FindSame.h)
