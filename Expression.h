#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "Utils.h"
#include "Token.h"
#include "Visitor.h"

abstract class Expression {
public:
    virtual String accept(Visitor &visitor) = 0;
};

#endif