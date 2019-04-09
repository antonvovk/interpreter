#ifndef BINARY_H
#define BINARY_H

#include "../Expression.h"

interface IBinary {
public:
    virtual std::shared_ptr<Expression> Left() const = 0;
    virtual Token Operatr() const = 0;
    virtual std::shared_ptr<Expression> Right() const = 0;
};

class Binary : public Expression, public IBinary {
public:
    explicit Binary(std::shared_ptr<Expression> left, Token operatr, std::shared_ptr<Expression> right);
    Object accept(Visitor &visitor) override;
    std::shared_ptr<Expression> Left() const override;
    Token Operatr() const override;
    std::shared_ptr<Expression> Right() const override;
private:
    std::shared_ptr<Expression> left;
    Token operatr;
    std::shared_ptr<Expression> right;
};

#endif