#ifndef CALL_H
#define CALL_H

#include "../Expression.h"

interface ICall {
public:
    virtual std::shared_ptr<Expression> Callee() const = 0;
    virtual Token Paren() const = 0;
    virtual Array<std::shared_ptr<Expression>> Arguments() const = 0;
};

class Call : public Expression, public ICall {
public:
    explicit Call(std::shared_ptr<Expression> callee, Token paren, Array<std::shared_ptr<Expression>> arguments);
    Object accept(Visitor &visitor) override;
    std::shared_ptr<Expression> Callee() const override;
    Token Paren() const override;
    Array<std::shared_ptr<Expression>> Arguments() const override;
private:
    std::shared_ptr<Expression> callee;
    Token paren;
    Array<std::shared_ptr<Expression>> arguments;
};

#endif
