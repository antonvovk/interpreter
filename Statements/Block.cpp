#include "Block.h"

Block::Block(Array<std::shared_ptr<Statement>> statements) : statements(std::move(statements)) {

}

Object Block::accept(Statement::Visitor &visitor) {
    return visitor.visit(*this);
}

Array<std::shared_ptr<Statement>> Block::Statements() const {
    return statements;
}