#ifndef UNARY_H
#define UNARY_H

#include "../Expression.h"

interface IUnary {
public:
    virtual Token Operatr() const = 0;
    virtual Expression* Right() const = 0;
};

class Unary : public Expression, public IUnary {
public:
    explicit Unary(Token operatr, Expression* right);
    Object accept(Visitor &visitor) override;
    Token Operatr() const override;
    Expression* Right() const override;
private:
    Token operatr;
    Expression* right;
};

#endif