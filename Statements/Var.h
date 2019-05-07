#ifndef VAR_H
#define VAR_H

#include "../Statement.h"
#include "../Expression.h"

interface IVar {
public:
    virtual Token Name() const = 0;
    virtual std::shared_ptr<Expression> Initializer() const = 0;
    virtual String Type() const = 0;
};

class Var : public Statement, public IVar {
public:
    explicit Var(Token name, std::shared_ptr<Expression> initializer, String type);
    Object accept(Visitor &visitor) override;
    Token Name() const override;
    std::shared_ptr<Expression> Initializer() const override;
    String Type() const override;
private:
    String type;
    Token name;
    std::shared_ptr<Expression> initializer;
};

#endif
