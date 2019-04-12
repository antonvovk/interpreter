#include "If.h"

If::If(std::shared_ptr<Expression> condition, std::shared_ptr<Statement> thenBranch, std::shared_ptr<Statement> elseBranch) :
    condition(std::move(condition)), thenBranch(std::move(thenBranch)), elseBranch(std::move(elseBranch)) {

}

Object If::accept(Statement::Visitor &visitor) {
    return visitor.visit(*this);
}

std::shared_ptr<Expression> If::Condition() const {
    return condition;
}

std::shared_ptr<Statement> If::ThenBranch() const {
    return thenBranch;
}

std::shared_ptr<Statement> If::ElseBranch() const {
    return elseBranch;
}
