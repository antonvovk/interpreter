#include "This.h"

This::This(Token keyword) : keyword(std::move(keyword)) {

}

Object This::accept(Visitor &visitor) {
    return visitor.visit(*this);
}

Token This::Keyword() const {
    return this->keyword;
}