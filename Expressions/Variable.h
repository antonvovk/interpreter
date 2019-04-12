#ifndef VARIABLE_H
#define VARIABLE_H

#include "../Expression.h"

interface IVariable {
public:
    virtual Token Name() const = 0;
};

class Variable : public Expression, public IVariable {
public:
    explicit Variable() = default;
    explicit Variable(Token name);
    Object accept(Visitor &visitor) override;
    Token Name() const override;
private:
    Token name;
};

#endif
