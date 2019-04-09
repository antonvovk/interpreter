#include "Assign.h"

Assign::Assign(Token name, std::shared_ptr<Expression> value) : name(std::move(name)), value(std::move(value)) {

}

Object Assign::accept(Visitor &visitor) {
    return visitor.visit(*this);
}

Token Assign::Name() const {
    return this->name;
}

std::shared_ptr<Expression> Assign::Value() const {
    return this->value;
}