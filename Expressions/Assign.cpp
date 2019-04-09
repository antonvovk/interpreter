#include "Assign.h"

Assign::Assign(Token name, Expression* value) : name(std::move(name)), value(value) {

}

Object Assign::accept(Visitor &visitor) {
    return visitor.visit(*this);
}

Token Assign::Name() const {
    return this->name;
}

Expression* Assign::Value() const {
    return this->value;
}