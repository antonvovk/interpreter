#include "Printer.h"

String Printer::print(Expression *expr) {
    return std::any_cast<String>(expr->accept(*this));
}

Object Printer::visit(Assign &expr) {
    return "";
}

Object Printer::visit(Binary &expr) {
    return parenthesize(expr.Operatr().Lexeme(), {expr.Left(), expr.Right()});
}

Object Printer::visit(Call &expr) {
    return "";
}

Object Printer::visit(Get &expr) {
    return "";
}

Object Printer::visit(Grouping &expr) {
    return parenthesize("group", {expr.Expr()});
}

Object Printer::visit(Literal &expr) {
    if (std::any_cast<String>(expr.Value()).empty()) {
        return "nil";
    }

    return expr.Value();
}

Object Printer::visit(Logical &expr) {
    return "";
}

Object Printer::visit(Set &expr) {
    return "";
}

Object Printer::visit(Super &expr) {
    return "";
}

Object Printer::visit(This &expr) {
    return "";
}

Object Printer::visit(Unary &expr) {
    return parenthesize(expr.Operatr().Lexeme(), {expr.Right()});
}

Object Printer::visit(Variable &expr) {
    return "";
}

String Printer::parenthesize(const String& name, std::initializer_list<Expression*> exprs) {
    String builder;
    builder.append("(").append(name);

    for (Expression* expr : exprs) {
        builder.append(" ");
        builder.append(std::any_cast<String>(expr->accept(*this)));
    }

    builder.append(")");
    return builder;
}