#ifndef BLOCK_H
#define BLOCK_H

#include "../Statement.h"

interface IBlock {
public:
    virtual Array<std::shared_ptr<Statement>> Statements() const = 0;
};

class Block : public Statement, public IBlock {
public:
    explicit Block(Array<std::shared_ptr<Statement>> statements);
    Object accept(Visitor &visitor) override ;
    Array<std::shared_ptr<Statement>> Statements() const override;
private:
    Array<std::shared_ptr<Statement>> statements;
};

#endif
