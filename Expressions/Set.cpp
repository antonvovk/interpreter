#include "Set.h"

Set::Set(std::shared_ptr<Expression> object, Token name, std::shared_ptr<Expression> value) : object(std::move(object)), name(std::move(name)), value(std::move(value)) {

}

Object Set::accept(Visitor &visitor) {
    return visitor.visit(*this);
}

std::shared_ptr<Expression> Set::Obj() const {
    return this->object;
}

Token Set::Name() const {
    return this->name;
}

std::shared_ptr<Expression> Set::Value() const {
    return this->value;
}