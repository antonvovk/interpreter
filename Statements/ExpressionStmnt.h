#ifndef EXPRESSIONSTMNT_H
#define EXPRESSIONSTMNT_H

#include "../Statement.h"
#include "../Expression.h"

interface IExpressionStmnt {
public:
    virtual std::shared_ptr<Expression> Expr() const = 0;
};

class ExpressionStmnt : public Statement, public IExpressionStmnt{
public:
    explicit ExpressionStmnt(std::shared_ptr<Expression> expression);
    Object accept(Visitor &visitor) override;
    std::shared_ptr<Expression> Expr() const override;
private:
    std::shared_ptr<Expression> expression;
};

#endif