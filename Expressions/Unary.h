#ifndef UNARY_H
#define UNARY_H

#include "../Expression.h"

interface IUnary {
public:
    virtual Token Operatr() const = 0;
    virtual std::shared_ptr<Expression> Right() const = 0;
};

class Unary : public Expression, public IUnary {
public:
    explicit Unary(Token operatr, std::shared_ptr<Expression> right);
    Object accept(Visitor &visitor) override;
    Token Operatr() const override;
    std::shared_ptr<Expression> Right() const override;
private:
    Token operatr;
    std::shared_ptr<Expression> right;
};

#endif