#include "Literal.h"

Literal::Literal(Object value) : value(std::move(value)) {

}

Object Literal::accept(Visitor &visitor) {
    return visitor.visit(*this);
}

Object Literal::Value() const {
    return this->value;
}
