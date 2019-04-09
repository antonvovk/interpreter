#include "Logical.h"

Logical::Logical(std::shared_ptr<Expression> left, Token operatr, std::shared_ptr<Expression> right) : left(std::move(left)), operatr(std::move(operatr)), right(std::move(right)) {

}

Object Logical::accept(Visitor &visitor) {
    return visitor.visit(*this);
}

std::shared_ptr<Expression> Logical::Left() const {
    return this->left;
}

Token Logical::Operatr() const {
    return this->operatr;
}

std::shared_ptr<Expression> Logical::Right() const {
    return this->right;
}