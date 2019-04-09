#ifndef THIS_H
#define THIS_H

#include "../Expression.h"

interface IThis {
public:
    virtual Token Keyword() const = 0;
};

class This : public Expression, public IThis {
public:
    explicit This(Token keyword);
    Object accept(Visitor &visitor) override;
    Token Keyword() const override;
private:
    Token keyword;
};

#endif
