#include "Unary.h"

Unary::Unary(Token operatr, std::shared_ptr<Expression> right) : operatr(std::move(operatr)), right(std::move(right)) {

}

Object Unary::accept(Visitor &visitor) {
    return visitor.visit(*this);
}

Token Unary::Operatr() const {
    return this->operatr;
}

std::shared_ptr<Expression> Unary::Right() const {
    return this->right;
}