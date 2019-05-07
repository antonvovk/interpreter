#ifndef COPY_H
#define COPY_H

#include "../Statement.h"
#include "../Expression.h"

interface ICopy {
    virtual std::shared_ptr<Expression> Expr1() const = 0;
    virtual std::shared_ptr<Expression> Expr2() const = 0;
};

class Copy : public Statement, public ICopy {
public:
    explicit Copy(std::shared_ptr<Expression> expression1, std::shared_ptr<Expression> expression2);
    Object accept(Visitor &visitor) override;
    std::shared_ptr<Expression> Expr1() const override;
    std::shared_ptr<Expression> Expr2() const override;
private:
    std::shared_ptr<Expression> expression1, expression2;
};

#endif
