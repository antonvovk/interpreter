#include "Print.h"

Print::Print(std::shared_ptr<Expression> expression) : expression(std::move(expression)) {

}

Object Print::accept(Statement::Visitor &visitor) {
    return visitor.visit(*this);
}

std::shared_ptr<Expression> Print::Expr() const {
    return expression;
}
