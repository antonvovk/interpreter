#ifndef GROUPING_H
#define GROUPING_H

#include "../Expression.h"

interface IGrouping {
public:
    virtual Expression* Expr() const = 0;
};

class Grouping : public Expression, public IGrouping {
public:
    explicit Grouping(Expression* expression);
    String accept(Visitor &visitor) override;
    Expression* Expr() const override;
private:
    Expression* expr;
};

#endif