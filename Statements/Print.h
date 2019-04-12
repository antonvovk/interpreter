#ifndef PRINT_H
#define PRINT_H

#include "../Statement.h"
#include "../Expression.h"

interface IPrint {
    virtual std::shared_ptr<Expression> Expr() const = 0;
};

class Print : public Statement, public IPrint {
public:
    explicit Print(std::shared_ptr<Expression> expression);
    Object accept(Visitor &visitor) override;
    std::shared_ptr<Expression> Expr() const override;
private:
    std::shared_ptr<Expression> expression;
};


#endif
