#include "Remove.h"

Remove::Remove(std::shared_ptr<Expression> expression) : expression(std::move(expression)) {

}

Object Remove::accept(Statement::Visitor &visitor) {
    return visitor.visit(*this);
}

std::shared_ptr<Expression> Remove::Expr() const {
    return expression;
}
