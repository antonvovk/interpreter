#ifndef ASSIGN_H
#define ASSIGN_H

#include "../Expression.h"

interface IAssign {
public:
    virtual Token Name() const = 0;
    virtual std::shared_ptr<Expression> Value() const = 0;
};

class Assign : public Expression, public IAssign {
public:
    explicit Assign(Token name, std::shared_ptr<Expression> value);
    Object accept(Visitor &visitor) override;
    Token Name() const override;
    std::shared_ptr<Expression> Value() const override;
private:
    Token name;
    std::shared_ptr<Expression> value;
};

#endif