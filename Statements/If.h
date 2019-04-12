#ifndef IF_H
#define IF_H

#include "../Statement.h"
#include "../Expression.h"

interface IIf {
public:
    virtual std::shared_ptr<Expression> Condition() const = 0;
    virtual std::shared_ptr<Statement> ThenBranch() const = 0;
    virtual std::shared_ptr<Statement> ElseBranch() const = 0;
};

class If : public Statement, public IIf {
public:
    explicit If(std::shared_ptr<Expression>  condition, std::shared_ptr<Statement> thenBranch, std::shared_ptr<Statement> elseBranch);
    Object accept(Visitor &visitor) override;
    std::shared_ptr<Expression> Condition() const override;
    std::shared_ptr<Statement> ThenBranch() const override;
    std::shared_ptr<Statement> ElseBranch() const override;
private:
    std::shared_ptr<Expression>  condition;
    std::shared_ptr<Statement> thenBranch;
    std::shared_ptr<Statement> elseBranch;
};


#endif