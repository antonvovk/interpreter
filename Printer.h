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

class Printer : public Visitor {
public:
    String print(Expression *expr) {
        return expr->accept(*this);
    }

    String visit(Assign &expr) override {
        return "";
    }

    String visit(Binary &expr) override {
        Array<Expression*> exprs;
        exprs.push_back(expr.Left());
        exprs.push_back(expr.Right());
        return parenthesize(expr.Operatr().Lexeme(), exprs);
    }

    String visit(Call &expr) override {
        return "";
    }

    String visit(Get &expr) override {
        return "";
    }

    String visit(Grouping &expr) override {
        Array<Expression*> exprs;
        exprs.push_back(expr.Expr());
        return parenthesize("group", exprs);
    }

    String visit(Literal &expr) override {
        if (expr.Value().empty()) {
            return "nil";
        }

        return expr.Value();
    }

    String visit(Logical &expr) override {
        return "";
    }

    String visit(Set &expr) override {
        return "";
    }

    String visit(Super &expr) override {
        return "";
    }

    String visit(This &expr) override {
        return "";
    }

    String visit(Unary &expr) override {
        Array<Expression*> exprs;
        exprs.push_back(expr.Right());
        return parenthesize(expr.Operatr().Lexeme(), exprs);
    }

    String visit(Variable &expr) override {
        return "";
    }

    String parenthesize(const String& name, Array<Expression*> exprs) {
        String builder;

        builder.append("(").append(name);
        for (Expression* expr : exprs) {
            builder.append(" ");
            builder.append(expr->accept(*this));
        }
        builder.append(")");

        return builder;
    }
};

#endif