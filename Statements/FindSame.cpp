#include "FindSame.h"

FindSame::FindSame(std::shared_ptr<Expression> expression) : expression(std::move(expression)) {

}

Object FindSame::accept(Statement::Visitor &visitor) {
    return visitor.visit(*this);
}

std::shared_ptr<Expression> FindSame::Expr() const {
    return expression;
}
