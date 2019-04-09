#ifndef LITERAL_H
#define LITERAL_H

#include "../Expression.h"

interface ILiteral {
public:
    virtual Object Value() const = 0;
};

class Literal : public Expression, public ILiteral {
public:
    explicit Literal(Object value);
    Object accept(Visitor &visitor) override;
    Object Value() const override;
private:
    Object value;
};

#endif