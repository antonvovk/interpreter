#include "Binary.h"

Binary::Binary(std::shared_ptr<Expression> left, Token operatr, std::shared_ptr<Expression> right) : left(std::move(left)), operatr(std::move(operatr)), right(std::move(right)) {

}

Object Binary::accept(Visitor &visitor) {
    return visitor.visit(*this);
}

std::shared_ptr<Expression> Binary::Left() const {
    return this->left;
}

Token Binary::Operatr() const {
    return this->operatr;
}

std::shared_ptr<Expression> Binary::Right() const {
    return this->right;
}