#ifndef PRINTER_H
#define PRINTER_H

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

interface IPrinter {
public:
    virtual String print(Expression *expr) = 0;
};

class Printer : public Expression::Visitor, public IPrinter {
public:
    String print(Expression *expr) override;
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
    String parenthesize(const String& name, std::initializer_list<Expression*> exprs);
};

#endif