#include "Grouping.h"

Grouping::Grouping(Expression* expr) : expr(expr) {

}

String Grouping::accept(Visitor &visitor) {
    return visitor.visit(*this);
}

Expression* Grouping::Expr() const {
    return this->expr;
}