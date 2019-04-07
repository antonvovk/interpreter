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
    String visit(Assign &expr) override;
    String visit(Binary &expr) override;
    String visit(Call &expr) override;
    String visit(Get &expr) override;
    String visit(Grouping &expr) override;
    String visit(Literal &expr) override;
    String visit(Logical &expr) override;
    String visit(Set &expr) override;
    String visit(Super &expr) override;
    String visit(This &expr) override;
    String visit(Unary &expr) override;
    String visit(Variable &expr) override;
    String parenthesize(const String& name, std::initializer_list<Expression*> exprs);
};

#endif