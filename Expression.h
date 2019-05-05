#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "Utils.h"
#include "Token.h"

class Assign;
class Binary;
class Grouping;
class Literal;
class Logical;
class Unary;
class Variable;

abstract class Expression {
public:
    interface Visitor {
    public:
        virtual Object visit(Assign &expr) = 0;
        virtual Object visit(Binary &expr) = 0;
        virtual Object visit(Grouping &expr) = 0;
        virtual Object visit(Literal &expr) = 0;
        virtual Object visit(Logical &expr) = 0;
        virtual Object visit(Unary &expr) = 0;
        virtual Object visit(Variable &expr) = 0;
    };

    virtual Object accept(Visitor &visitor) = 0;
};

#endif