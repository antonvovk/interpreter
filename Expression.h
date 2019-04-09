#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "Utils.h"
#include "Token.h"

class Assign;
class Binary;
class Call;
class Get;
class Grouping;
class Literal;
class Logical;
class Set;
class Super;
class This;
class Unary;
class Variable;

abstract class Expression {
public:
    interface Visitor {
    public:
        virtual Object visit(Assign &expr) = 0;
        virtual Object visit(Binary &expr) = 0;
        virtual Object visit(Call &expr) = 0;
        virtual Object visit(Get &expr) = 0;
        virtual Object visit(Grouping &expr) = 0;
        virtual Object visit(Literal &expr) = 0;
        virtual Object visit(Logical &expr) = 0;
        virtual Object visit(Set &expr) = 0;
        virtual Object visit(Super &expr) = 0;
        virtual Object visit(This &expr) = 0;
        virtual Object visit(Unary &expr) = 0;
        virtual Object visit(Variable &expr) = 0;
    };

    virtual Object accept(Visitor &visitor) = 0;
};

#endif