#include "Grouping.h"

Grouping::Grouping(Expression* expr) : expr(expr) {

}

Object Grouping::accept(Visitor &visitor) {
    return visitor.visit(*this);
}

Expression* Grouping::Expr() const {
    return this->expr;
}