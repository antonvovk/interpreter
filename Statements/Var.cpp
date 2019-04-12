#include "Var.h"

Var::Var(Token name, std::shared_ptr<Expression> initializer) : name(std::move(name)), initializer(std::move(initializer)) {

}

Object Var::accept(Statement::Visitor &visitor) {
    return visitor.visit(*this);
}

Token Var::Name() const {
    return name;
}

std::shared_ptr<Expression> Var::Initializer() const {
    return initializer;
}
