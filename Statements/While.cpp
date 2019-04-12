#include "While.h"

While::While(std::shared_ptr<Expression> condition, std::shared_ptr<Statement> body) : condition(std::move(condition)), body(std::move(body)) {

}

Object While::accept(Statement::Visitor &visitor) {
    return visitor.visit(*this);
}

std::shared_ptr<Expression> While::Condition() const {
    return condition;
}

std::shared_ptr<Statement> While::Body() const {
    return body;
}
