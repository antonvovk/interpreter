#include "Printer.h"

String Printer::print(std::shared_ptr<Expression> expr) {
    return objectToString(expr->accept(*this));
}

Object Printer::visit(Assign &expr) {
    return String("");
}

Object Printer::visit(Binary &expr) {
    return parenthesize(expr.Operatr().Lexeme(), {expr.Left(), expr.Right()});
}

Object Printer::visit(Call &expr) {
    return String("");
}

Object Printer::visit(Get &expr) {
    return String("");
}

Object Printer::visit(Grouping &expr) {
    return parenthesize("group", {expr.Expr()});
}

Object Printer::visit(Literal &expr) {
    return expr.Value();
}

Object Printer::visit(Logical &expr) {
    return String("");
}

Object Printer::visit(Set &expr) {
    return String("");
}

Object Printer::visit(Super &expr) {
    return String("");
}

Object Printer::visit(This &expr) {
    return String("");
}

Object Printer::visit(Unary &expr) {
    return parenthesize(expr.Operatr().Lexeme(), {expr.Right()});
}

Object Printer::visit(Variable &expr) {
    return String("");
}

String Printer::parenthesize(const String& name, std::initializer_list<std::shared_ptr<Expression>> exprs) {
    String builder;
    builder.append("(").append(name);

    for (const std::shared_ptr<Expression>& expr : exprs) {
        builder.append(" ");
        builder.append(objectToString(expr->accept(*this)));
    }

    builder.append(")");
    return builder;
}