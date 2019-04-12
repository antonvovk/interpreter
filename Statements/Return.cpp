#include "Return.h"

Return::Return(Token keyword, std::shared_ptr<Expression> value) : keyword(std::move(keyword)), value(std::move(value)) {

}

Object Return::accept(Statement::Visitor &visitor) {
    return visitor.visit(*this);
}

Token Return::Keyword() const {
    return keyword;
}

std::shared_ptr<Expression> Return::Value() const {
    return value;
}
