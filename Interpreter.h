#ifndef INTERPRETER_H
#define INTERPRETER_H

#include "Expression.h"
#include "Expressions/Assign.h"
#include "Expressions/Binary.h"
#include "Expressions/Call.h"
#include "Expressions/Get.h"
#include "Expressions/Grouping.h"
#include "Expressions/Literal.h"
#include "Expressions/Logical.h"
#include "Expressions/Set.h"
#include "Expressions/Super.h"
#include "Expressions/This.h"
#include "Expressions/Unary.h"
#include "Expressions/Variable.h"
#include "RuntimeError.h"

interface IInterpreter {
public:
    virtual void interpret(std::shared_ptr<Expression> expression) = 0;
};

class Interpreter : public IInterpreter, public Expression::Visitor {
public:
    void interpret(std::shared_ptr<Expression> expression) override ;
private:
    Object visit(Assign &expr) override;
    Object visit(Binary &expr) override;
    Object visit(Call &expr) override;
    Object visit(Get &expr) override;
    Object visit(Grouping &expr) override;
    Object visit(Literal &expr) override;
    Object visit(Logical &expr) override;
    Object visit(Set &expr) override;
    Object visit(Super &expr) override;
    Object visit(This &expr) override;
    Object visit(Unary &expr) override;
    Object visit(Variable &expr) override;
    Object evaluate(const std::shared_ptr<Expression>& expr);
    static bool isTruthy(Object object);
    static bool isEqual(const Object& a, const Object& b);
    static void checkNumberOperand(Token operatr, const Object& operand);
    static void checkNumberOperands(Token operatr, const Object& left, const Object& right);
};

#endif
