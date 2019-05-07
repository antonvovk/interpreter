#ifndef REMOVE_H
#define REMOVE_H

#include "../Statement.h"
#include "../Expression.h"

interface IRemove {
    virtual std::shared_ptr<Expression> Expr() const = 0;
};

class Remove : public Statement, public IRemove {
public:
    explicit Remove(std::shared_ptr<Expression> expression);
    Object accept(Visitor &visitor) override;
    std::shared_ptr<Expression> Expr() const override;
private:
    std::shared_ptr<Expression> expression;
};

#endif
