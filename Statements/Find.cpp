#include "Find.h"

Find::Find(std::shared_ptr<Expression> expression) : expression(std::move(expression)) {

}

Object Find::accept(Statement::Visitor &visitor) {
    return visitor.visit(*this);
}

std::shared_ptr<Expression> Find::Expr() const {
    return expression;
}
