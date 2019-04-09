#ifndef GROUPING_H
#define GROUPING_H

#include "../Expression.h"

interface IGrouping {
public:
    virtual std::shared_ptr<Expression> Expr() const = 0;
};

class Grouping : public Expression, public IGrouping {
public:
    explicit Grouping(std::shared_ptr<Expression> expression);
    Object accept(Visitor &visitor) override;
    std::shared_ptr<Expression> Expr() const override;
private:
    std::shared_ptr<Expression> expr;
};

#endif