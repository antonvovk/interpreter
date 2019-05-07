#ifndef PARSER_H
#define PARSER_H

#include "Expression.h"
#include "Expressions/Assign.h"
#include "Expressions/Binary.h"
#include "Expressions/Grouping.h"
#include "Expressions/Literal.h"
#include "Expressions/Logical.h"
#include "Expressions/Unary.h"
#include "Expressions/Variable.h"
#include "Statement.h"
#include "Statements/Block.h"
#include "Statements/ExpressionStmnt.h"
#include "Statements/If.h"
#include "Statements/Print.h"
#include "Statements/Move.h"
#include "Statements/Copy.h"
#include "Statements/Remove.h"
#include "Statements/Find.h"
#include "Statements/FindSame.h"
#include "Statements/Var.h"
#include "Statements/While.h"

interface IParser {
public:
    virtual Array<std::shared_ptr<Statement>> parse() = 0;
};

class Parser : public IParser {
public:
    explicit Parser(Array<Token> tokens);
    Array<std::shared_ptr<Statement>> parse() override;
private:
    std::shared_ptr<Statement> statement();
    std::shared_ptr<Statement> ifStatement();
    std::shared_ptr<Statement> whileStatement();
    Array<std::shared_ptr<Statement>> block();
    std::shared_ptr<Statement> printStatement();
    std::shared_ptr<Statement> moveStatement();
    std::shared_ptr<Statement> copyStatement();
    std::shared_ptr<Statement> removeStatement();
    std::shared_ptr<Statement> findStatement();
    std::shared_ptr<Statement> find_sameStatement();
    std::shared_ptr<Statement> expressionStatement();
    std::shared_ptr<Statement> declaration();
    std::shared_ptr<Statement> floatVarDeclaration();
    std::shared_ptr<Statement> intVarDeclaration();
    std::shared_ptr<Statement> stringVarDeclaration();
    std::shared_ptr<Statement> charVarDeclaration();
    std::shared_ptr<Statement> fileVarDeclaration();
    std::shared_ptr<Statement> boolVarDeclaration();
    std::shared_ptr<Expression> expression();
    std::shared_ptr<Expression> assignment();
    std::shared_ptr<Expression> equality();
    bool match(std::initializer_list<TokenType> types);
    bool check(TokenType type) const;
    Token advance();
    bool isAtEnd() const;
    Token peek() const;
    Token previous() const;
    std::shared_ptr<Expression> comparison();
    std::shared_ptr<Expression> addition();
    std::shared_ptr<Expression> multiplication();
    std::shared_ptr<Expression> unary();
    std::shared_ptr<Expression> primary();
    std::shared_ptr<Expression> OR();
    std::shared_ptr<Expression> AND();
    Token consume(TokenType type, const String& message);
    void error(const Token& token, const String& message) const;

    Array<Token> tokens{};
    int current{};
};

#endif
