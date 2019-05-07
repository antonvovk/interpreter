#ifndef FIND_H
#define FIND_H

#include "../Statement.h"
#include "../Expression.h"

interface IFind {
    virtual std::shared_ptr<Expression> Expr() const = 0;
};

class Find : public Statement, public IFind {
public:
    explicit Find(std::shared_ptr<Expression> expression);
    Object accept(Visitor &visitor) override;
    std::shared_ptr<Expression> Expr() const override;
private:
    std::shared_ptr<Expression> expression;
};

#endif
