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

interface IParser {
public:
    virtual Expression* parse() = 0;
};

class Parser : public IParser {
public:
    explicit Parser(Array<Token> tokens);
    Expression* parse() override;
private:
    Expression* expression();
    Expression* equality();
    bool match(std::initializer_list<TokenType> types);
    bool check(TokenType type) const;
    Token advance();
    bool isAtEnd() const;
    Token peek() const;
    Token previous() const;
    Expression* comparison();
    Expression* addition();
    Expression* multiplication();
    Expression* unary();
    Expression* primary();
    Token consume(TokenType type, const String& message);
    ParseError error(const Token& token, const String& message) const;
    void synchronize();

    Array<Token> tokens{};
    int current{};
};

#endif