#include "Function.h"

Function::Function(Token name, Array<Token> params, Array<std::shared_ptr<Statement>> body) : name(std::move(name)), params(std::move(params)), body(std::move(body)) {

}

Object Function::accept(Statement::Visitor &visitor) {
    return visitor.visit(*this);
}

Token Function::Name() const {
    return name;
}

Array<Token> Function::Params() const {
    return params;
}

Array<std::shared_ptr<Statement>> Function::Body() const {
    return body;
}
