#ifndef CLASS_H
#define CLASS_H

#include "../Statement.h"
#include "../Expressions/Variable.h"
#include "../Statements/Function.h"

interface IClass {
public:
    virtual Token Name() const = 0;
    virtual Variable Superclass() const = 0;
    virtual Array<Function> Methods() const = 0;
};

class Class : public Statement, public IClass {
public:
    explicit Class(Token name, Variable superclass, Array<Function> methods);
    Object accept(Visitor &visitor) override;
    Token Name() const override;
    Variable Superclass() const override;
    Array<Function> Methods() const override;
private:
    Token name;
    Variable superclass;
    Array<Function> methods;
};


#endif
