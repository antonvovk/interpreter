#ifndef SET_H
#define SET_H

#include "../Expression.h"

interface ISet {
public:
    virtual Expression* Object() const = 0;
    virtual Token Name() const = 0;
    virtual Expression* Value() const = 0;
};

class Set : public Expression, public ISet {
public:
    explicit Set(Expression* object, Token name, Expression* value);
    String accept(Visitor &visitor) override;
    Expression* Object() const override;
    Token Name() const override;
    Expression* Value() const override;
private:
    Expression* object;
    Token name;
    Expression* value;
};

#endif