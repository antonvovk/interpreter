#ifndef SET_H
#define SET_H

#include "../Expression.h"

interface ISet {
public:
    virtual std::shared_ptr<Expression> Obj() const = 0;
    virtual Token Name() const = 0;
    virtual std::shared_ptr<Expression> Value() const = 0;
};

class Set : public Expression, public ISet {
public:
    explicit Set(std::shared_ptr<Expression> object, Token name, std::shared_ptr<Expression> value);
    Object accept(Visitor &visitor) override;
    std::shared_ptr<Expression> Obj() const override;
    Token Name() const override;
    std::shared_ptr<Expression> Value() const override;
private:
    std::shared_ptr<Expression> object;
    Token name;
    std::shared_ptr<Expression> value;
};

#endif