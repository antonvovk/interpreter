#include "Call.h"

Call::Call(std::shared_ptr<Expression> callee, Token paren, Array<std::shared_ptr<Expression>> arguments) : callee(std::move(callee)), paren(std::move(paren)), arguments(std::move(arguments)) {

}

Object Call::accept(Visitor &visitor) {
    return visitor.visit(*this);
}

std::shared_ptr<Expression> Call::Callee() const {
    return this->callee;
}

Token Call::Paren() const {
    return this->paren;
}

Array<std::shared_ptr<Expression>> Call::Arguments() const {
    return this->arguments;
}