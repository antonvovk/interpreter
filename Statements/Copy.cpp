#include "Copy.h"

Copy::Copy(std::shared_ptr<Expression> expression1, std::shared_ptr<Expression> expression2) : expression1(std::move(expression1)), expression2(std::move(expression2)) {

}

Object Copy::accept(Statement::Visitor &visitor) {
    return visitor.visit(*this);
}

std::shared_ptr<Expression> Copy::Expr1() const {
    return expression1;
}

std::shared_ptr<Expression> Copy::Expr2() const {
    return expression2;
}
