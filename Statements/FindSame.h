#ifndef FINDSAME_H
#define FINDSAME_H

#include "../Statement.h"
#include "../Expression.h"

interface IFindSame {
    virtual std::shared_ptr<Expression> Expr() const = 0;
};

class FindSame : public Statement, public IFindSame {
public:
    explicit FindSame(std::shared_ptr<Expression> expression);
    Object accept(Visitor &visitor) override;
    std::shared_ptr<Expression> Expr() const override;
private:
    std::shared_ptr<Expression> expression;
};

#endif
