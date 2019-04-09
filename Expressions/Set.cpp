#include "Set.h"

Set::Set(Expression* object, Token name, Expression* value) : object(object), name(std::move(name)), value(value) {

}

Object Set::accept(Visitor &visitor) {
    return visitor.visit(*this);
}

Expression* Set::Obj() const {
    return this->object;
}

Token Set::Name() const {
    return this->name;
}

Expression* Set::Value() const {
    return this->value;
}