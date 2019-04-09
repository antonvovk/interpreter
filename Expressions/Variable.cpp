#include "Variable.h"

Variable::Variable(Token name) : name(std::move(name)) {

}

Object Variable::accept(Visitor &visitor) {
    return visitor.visit(*this);
}

Token Variable::Name() const {
    return this->name;
}