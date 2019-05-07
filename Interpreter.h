#ifndef INTERPRETER_H
#define INTERPRETER_H

#include "Expression.h"
#include "Expressions/Assign.h"
#include "Expressions/Binary.h"
#include "Expressions/Grouping.h"
#include "Expressions/Literal.h"
#include "Expressions/Logical.h"
#include "Expressions/Unary.h"
#include "Expressions/Variable.h"
#include "RuntimeError.h"
#include "Statement.h"
#include "Statements/Block.h"
#include "Statements/ExpressionStmnt.h"
#include "Statements/If.h"
#include "Statements/Print.h"
#include "Statements/Move.h"
#include "Statements/Copy.h"
#include "Statements/Remove.h"
#include "Statements/Find.h"
#include "Statements/FindSame.h"
#include "Statements/Var.h"
#include "Statements/While.h"
#include "Environment.h"

interface IInterpreter {
public:
    virtual void interpret(Array<std::shared_ptr<Statement>> expression) = 0;
};

class Interpreter : public IInterpreter, public Expression::Visitor, public Statement::Visitor {
public:
    void interpret(Array<std::shared_ptr<Statement>> statements) override ;
private:
    Object visit(Assign &expr) override;
    Object visit(Binary &expr) override;
    Object visit(Grouping &expr) override;
    Object visit(Literal &expr) override;
    Object visit(Logical &expr) override;
    Object visit(Unary &expr) override;
    Object visit(Variable &expr) override;
    Object evaluate(const std::shared_ptr<Expression>& expr);
    static bool isTruthy(Object object);
    static bool isEqual(const Object& a, const Object& b);
    static void checkNumberOperand(Token operatr, const Object& operand);
    static void checkNumberOperands(Token operatr, const Object& left, const Object& right);
    Object visit(Block &stmnt) override;
    Object visit(ExpressionStmnt &stmnt) override;
    Object visit(If &stmnt) override;
    Object visit(Print &stmnt) override;
    Object visit(Move &stmnt) override;
    Object visit(Copy &stmnt) override;
    Object visit(Remove &stmnt) override;
    Object visit(Find &stmnt) override;
    Object visit(FindSame &stmnt) override;
    Object visit(Var &stmnt) override;
    Object visit(While &stmnt) override;
    void execute(const std::shared_ptr<Statement>& stmt);
    void executeBlock(const Array<std::shared_ptr<Statement>>& statements, Environment environment_arg);

    Environment environment{};
};

#endif
