#ifndef BINARY_H
#define BINARY_H

#include "../Expression.h"

interface IBinary {
public:
    virtual Expression* Left() const = 0;
    virtual Token Operatr() const = 0;
    virtual Expression* Right() const = 0;
};

class Binary : public Expression, public IBinary {
public:
    explicit Binary(Expression* left, Token operatr, Expression* right);
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