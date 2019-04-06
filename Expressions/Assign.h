#ifndef ASSIGN_H
#define ASSIGN_H

#include "../Expression.h"

interface IAssign {
public:
    virtual Token Name() const = 0;
    virtual Expression* Value() const = 0;
};

class Assign : public Expression, public IAssign {
public:
    explicit Assign(Token name, Expression* value);
    String accept(Visitor &visitor) override;
    Token Name() const override;
    Expression* Value() const override;
private:
    Token name;
    Expression* value;
};

#endif