#include "Printer.h"

String Printer::print(Expression *expr) {
    return expr->accept(*this);
}

String Printer::visit(Assign &expr) {
    return "";
}

String Printer::visit(Binary &expr) {
    return parenthesize(expr.Operatr().Lexeme(), {expr.Left(), expr.Right()});
}

String Printer::visit(Call &expr) {
    return "";
}

String Printer::visit(Get &expr) {
    return "";
}

String Printer::visit(Grouping &expr) {
    return parenthesize("group", {expr.Expr()});
}

String Printer::visit(Literal &expr) {
    if (expr.Value().empty()) {
        return "nil";
    }

    return expr.Value();
}

String Printer::visit(Logical &expr) {
    return "";
}

String Printer::visit(Set &expr) {
    return "";
}

String Printer::visit(Super &expr) {
    return "";
}

String Printer::visit(This &expr) {
    return "";
}

String Printer::visit(Unary &expr) {
    return parenthesize(expr.Operatr().Lexeme(), {expr.Right()});
}

String Printer::visit(Variable &expr) {
    return "";
}

String Printer::parenthesize(const String& name, std::initializer_list<Expression*> exprs) {
    String builder;
    builder.append("(").append(name);

    for (Expression* expr : exprs) {
        builder.append(" ");
        builder.append(expr->accept(*this));
    }

    builder.append(")");
    return builder;
}