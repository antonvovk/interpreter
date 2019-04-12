#ifndef STATEMENT_H
#define STATEMENT_H

#include "Utils.h"
#include "Token.h"

class Block;
class Class;
class ExpressionStmnt;
class Function;
class If;
class Print;
class Return;
class Var;
class While;

abstract class Statement {
public:
    interface Visitor {
    public:
        virtual Object visit(Block &stmnt) = 0;
        virtual Object visit(Class &stmnt) = 0;
        virtual Object visit(ExpressionStmnt &stmnt) = 0;
        virtual Object visit(Function &stmnt) = 0;
        virtual Object visit(If &stmnt) = 0;
        virtual Object visit(Print &stmnt) = 0;
        virtual Object visit(Return &stmnt) = 0;
        virtual Object visit(Var &stmnt) = 0;
        virtual Object visit(While &stmnt) = 0;
    };

    virtual Object accept(Visitor &visitor) = 0;
};

#endif
