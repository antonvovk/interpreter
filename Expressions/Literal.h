#ifndef LITERAL_H
#define LITERAL_H

#include "../Expression.h"

interface ILiteral {
public:
    virtual String Value() const = 0;
};

class Literal : public Expression, public ILiteral {
public:
    explicit Literal(String value);
    String accept(Visitor &visitor) override;
    String Value() const override;
private:
    String value;
};

#endif