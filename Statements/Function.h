#ifndef FUNCTION_H
#define FUNCTION_H

#include "../Statement.h"

interface IFunction {
public:
    virtual Token Name() const = 0;
    virtual Array<Token> Params() const = 0;
    virtual Array<std::shared_ptr<Statement>> Body() const = 0;
};

class Function : public Statement, public IFunction {
public:
    explicit Function(Token name, Array<Token> params, Array<std::shared_ptr<Statement>> body);
    Object accept(Visitor &visitor) override;
    Token Name() const override;
    Array<Token> Params() const override;
    Array<std::shared_ptr<Statement>> Body() const override;
private:
    Token name;
    Array<Token> params;
    Array<std::shared_ptr<Statement>> body;
};

#endif