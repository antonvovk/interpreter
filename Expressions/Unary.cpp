#include "Unary.h"

Unary::Unary(Token operatr, Expression* right) : operatr(std::move(operatr)), right(right) {

}

Object Unary::accept(Visitor &visitor) {
    return visitor.visit(*this);
}

Token Unary::Operatr() const {
    return this->operatr;
}

Expression* Unary::Right() const {
    return this->right;
}