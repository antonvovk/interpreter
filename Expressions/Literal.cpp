#include "Literal.h"

Literal::Literal(String value) : value(std::move(value)) {

}

String Literal::accept(Visitor &visitor) {
    return visitor.visit(*this);
}

String Literal::Value() const {
    return this->value;
}
