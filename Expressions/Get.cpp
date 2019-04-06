#include "Get.h"

Get::Get(Expression* object, Token name) : object(object), name(std::move(name)) {

}

String Get::accept(Visitor &visitor) {
    return visitor.visit(*this);
}

Expression* Get::Object() const {
    return this->object;
}

Token Get::Name() const {
    return this->name;
}