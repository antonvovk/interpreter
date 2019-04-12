#include "ExpressionStmnt.h"

ExpressionStmnt::ExpressionStmnt(std::shared_ptr<Expression> expression) : expression(std::move(expression)) {

}

Object ExpressionStmnt::accept(Statement::Visitor &visitor) {
    return visitor.visit(*this);
}

std::shared_ptr<Expression> ExpressionStmnt::Expr() const {
    return expression;
}
