#include "Class.h"

Class::Class(Token name, Variable superclass, Array<Function> methods) : name(std::move(name)), superclass(std::move(superclass)), methods(std::move(methods)) {

}

Object Class::accept(Statement::Visitor &visitor) {
    return visitor.visit(*this);
}

Token Class::Name() const {
    return name;
}

Variable Class::Superclass() const {
    return superclass;
}

Array<Function> Class::Methods() const {
    return methods;
}
