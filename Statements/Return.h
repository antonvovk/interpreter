#ifndef RETURN_H
#define RETURN_H

#include "../Statement.h"
#include "../Expression.h"

interface IReturn {
public:
    virtual Token Keyword() const = 0;
    virtual std::shared_ptr<Expression> Value() const = 0;
};

class Return : public Statement, public IReturn {
public:
    explicit Return(Token keyword, std::shared_ptr<Expression> value);
    Object accept(Visitor &visitor) override;
    Token Keyword() const override;
    std::shared_ptr<Expression> Value() const override;
private:
    Token keyword;
    std::shared_ptr<Expression> value;
};

#endif