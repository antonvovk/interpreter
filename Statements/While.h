#ifndef WHILE_H
#define WHILE_H

#include "../Statement.h"
#include "../Expression.h"

interface IWhile {
public:
    virtual std::shared_ptr<Expression> Condition() const = 0;
    virtual std::shared_ptr<Statement> Body() const = 0;
};

class While : public Statement, public IWhile {
public:
    explicit While(std::shared_ptr<Expression> condition, std::shared_ptr<Statement> body);
    Object accept(Visitor &visitor) override;
    std::shared_ptr<Expression> Condition() const override;
    std::shared_ptr<Statement> Body() const override;
private:
    std::shared_ptr<Expression> condition;
    std::shared_ptr<Statement> body;
};

#endif
