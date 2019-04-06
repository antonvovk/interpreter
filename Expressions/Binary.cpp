#include "Binary.h"

Binary::Binary(Expression* left, Token operatr, Expression* right) : left(left), operatr(std::move(operatr)), right(right) {

}

String Binary::accept(Visitor &visitor) {
    return visitor.visit(*this);
}

Expression* Binary::Left() const {
    return this->left;
}

Token Binary::Operatr() const {
    return this->operatr;
}

Expression* Binary::Right() const {
    return this->right;
}