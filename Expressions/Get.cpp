#include "Get.h"

Get::Get(Expression* object, Token name) : object(object), name(std::move(name)) {

}

Object Get::accept(Visitor &visitor) {
    return visitor.visit(*this);
}

Expression* Get::Obj() const {
    return this->object;
}

Token Get::Name() const {
    return this->name;
}