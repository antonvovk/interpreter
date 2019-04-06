#ifndef VISITOR_H
#define VISITOR_H

#include "Utils.h"

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

interface Visitor {
public:
    virtual String visit(Assign &expr) = 0;
    virtual String visit(Binary &expr) = 0;
    virtual String visit(Call &expr) = 0;
    virtual String visit(Get &expr) = 0;
    virtual String visit(Grouping &expr) = 0;
    virtual String visit(Literal &expr) = 0;
    virtual String visit(Logical &expr) = 0;
    virtual String visit(Set &expr) = 0;
    virtual String visit(Super &expr) = 0;
    virtual String visit(This &expr) = 0;
    virtual String visit(Unary &expr) = 0;
    virtual String visit(Variable &expr) = 0;
};

#endif