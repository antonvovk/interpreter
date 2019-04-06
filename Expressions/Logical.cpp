#include "Logical.h"

Logical::Logical(Expression* left, Token operatr, Expression* right) : left(left), operatr(std::move(operatr)), right(right) {

}

String Logical::accept(Visitor &visitor) {
    return visitor.visit(*this);
}

Expression* Logical::Left() const {
    return this->left;
}

Token Logical::Operatr() const {
    return this->operatr;
}

Expression* Logical::Right() const {
    return this->right;
}