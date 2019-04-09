#ifndef GET_H
#define GET_H

#include "../Expression.h"

interface IGet {
public:
    virtual std::shared_ptr<Expression> Obj() const = 0;
    virtual Token Name() const = 0;
};

class Get : public Expression, public IGet {
public:
    explicit Get(std::shared_ptr<Expression> object, Token name);
    Object accept(Visitor &visitor) override;
    std::shared_ptr<Expression> Obj() const override;
    Token Name() const override;
private:
    std::shared_ptr<Expression> object;
    Token name;
};

#endif