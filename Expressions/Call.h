#ifndef CALL_H
#define CALL_H

#include "../Expression.h"

interface ICall {
public:
    virtual Expression* Callee() const = 0;
    virtual Token Paren() const = 0;
    virtual Array<Expression*> Arguments() const = 0;
};

class Call : public Expression, public ICall {
public:
    explicit Call(Expression* callee, Token paren, Array<Expression*> arguments);
    Object accept(Visitor &visitor) override;
    Expression* Callee() const override;
    Token Paren() const override;
    Array<Expression*> Arguments() const override;
private:
    Expression* callee;
    Token paren;
    Array<Expression*> arguments;
};

#endif
