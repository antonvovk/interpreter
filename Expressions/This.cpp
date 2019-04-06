#include "This.h"

This::This(Token keyword) : keyword(std::move(keyword)) {

}

String This::accept(Visitor &visitor) {
    return visitor.visit(*this);
}

Token This::Keyword() const {
    return this->keyword;
}