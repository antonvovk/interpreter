#ifndef PARSER_H
#define PARSER_H

#include "ParseError.h"
#include "Expression.h"
#include "Expressions/Assign.h"
#include "Expressions/Binary.h"
#include "Expressions/Call.h"
#include "Expressions/Get.h"
#include "Expressions/Grouping.h"
#include "Expressions/Literal.h"
#include "Expressions/Logical.h"
#include "Expressions/Set.h"
#include "Expressions/Super.h"
#include "Expressions/This.h"
#include "Expressions/Unary.h"
#include "Expressions/Variable.h"
#include "Statement.h"
#include "Statements/Block.h"
#include "Statements/Class.h"
#include "Statements/ExpressionStmnt.h"
#include "Statements/Function.h"
#include "Statements/If.h"
#include "Statements/Print.h"
#include "Statements/Return.h"
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
    std::shared_ptr<Statement> printStatement();
    std::shared_ptr<Statement> expressionStatement();
    std::shared_ptr<Expression> expression();
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
    Token consume(TokenType type, const String& message);
    ParseError error(const Token& token, const String& message) const;
    void synchronize();

    Array<Token> tokens{};
    int current{};
};

#endif