#include "Grouping.h"

Grouping::Grouping(std::shared_ptr<Expression> expr) : expr(std::move(expr)) {

}

Object Grouping::accept(Visitor &visitor) {
    return visitor.visit(*this);
}

std::shared_ptr<Expression> Grouping::Expr() const {
    return this->expr;
}