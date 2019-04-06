#ifndef LOGICAL_H
#define LOGICAL_H

#include "../Expression.h"

interface ILogical {
public:
    virtual Expression* Left() const = 0;
    virtual Token Operatr() const = 0;
    virtual Expression* Right() const = 0;
};

class Logical : public Expression, public ILogical {
public:
    explicit Logical(Expression* left, Token operatr, Expression* right);
    String accept(Visitor &visitor) override;
    Expression* Left() const override;
    Token Operatr() const override;
    Expression* Right() const override;
private:
    Expression* left;
    Token operatr;
    Expression* right;
};

#endif