#include "Super.h"

Super::Super(Token keyword, Token method) : keyword(std::move(keyword)), method(std::move(method)) {

}

Object Super::accept(Visitor &visitor) {
    return visitor.visit(*this);
}

Token Super::Keyword() const {
    return this->keyword;
}

Token Super::Method() const {
    return this->method;
}