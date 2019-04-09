#ifndef SUPER_H
#define SUPER_H

#include "../Expression.h"

interface ISuper {
public:
    virtual Token Keyword() const  = 0;
    virtual Token Method() const = 0;
};

class Super : public Expression, public ISuper {
public:
    explicit Super(Token keyword, Token method);
    Object accept(Visitor &visitor) override;
    Token Keyword() const override;
    Token Method() const override;
private:
    Token keyword;
    Token method;
};

#endif