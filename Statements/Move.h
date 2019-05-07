#ifndef MOVE_H
#define MOVE_H

#include "../Statement.h"
#include "../Expression.h"

interface IMove {
    virtual std::shared_ptr<Expression>& Expr1() = 0;
    virtual std::shared_ptr<Expression>& Expr2() = 0;
};

class Move : public Statement, public IMove {
public:
    explicit Move(std::shared_ptr<Expression> expression1, std::shared_ptr<Expression> expression2);
    Object accept(Visitor &visitor) override;
    std::shared_ptr<Expression>& Expr1() override;
    std::shared_ptr<Expression>& Expr2() override;
private:
    std::shared_ptr<Expression> expression1, expression2;
};

#endif
