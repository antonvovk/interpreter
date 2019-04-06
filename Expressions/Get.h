#ifndef GET_H
#define GET_H

#include "../Expression.h"

interface IGet {
public:
    virtual Expression* Object() const = 0;
    virtual Token Name() const = 0;
};

class Get : public Expression, public IGet {
public:
    explicit Get(Expression* object, Token name);
    String accept(Visitor &visitor) override;
    Expression* Object() const override;
    Token Name() const override;
private:
    Expression* object;
    Token name;
};

#endif