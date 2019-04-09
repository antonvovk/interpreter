#include "Get.h"

Get::Get(std::shared_ptr<Expression> object, Token name) : object(std::move(object)), name(std::move(name)) {

}

Object Get::accept(Visitor &visitor) {
    return visitor.visit(*this);
}

std::shared_ptr<Expression> Get::Obj() const {
    return this->object;
}

Token Get::Name() const {
    return this->name;
}