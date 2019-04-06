#include "Call.h"

Call::Call(Expression* callee, Token paren, Array<Expression*> arguments) : callee(callee), paren(std::move(paren)), arguments(std::move(arguments)) {

}

String Call::accept(Visitor &visitor) {
    return visitor.visit(*this);
}

Expression* Call::Callee() const {
    return this->callee;
}

Token Call::Paren() const {
    return this->paren;
}

Array<Expression*> Call::Arguments() const {
    return this->arguments;
}