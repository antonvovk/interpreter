#ifndef TOKEN_H
#define TOKEN_H

#include "Utils.h"

BETTER_ENUM (TokenType, int,
    LEFT_PAREN, RIGHT_PAREN, LEFT_BRACE, RIGHT_BRACE,
    COMMA, DOT, MINUS, PLUS, SEMICOLON, SLASH, STAR,

    BANG, BANG_EQUAL,
    EQUAL, EQUAL_EQUAL,
    GREATER, GREATER_EQUAL,
    LESS, LESS_EQUAL,

    IDENTIFIER, STRING, NUMBER,

    AND, CLASS, ELSE, FALSE, FUN, FOR, IF, NIL, OR,
    PRINT, RETURN, SUPER, THIS, TRUE, VAR, WHILE,

    EOFL
)

interface IToken {
public:
    virtual String toString() const = 0;
};

class Token : public IToken {
public:
    explicit Token(TokenType type, String lexeme, String literal, int line);
    String toString() const override ;
private:
    TokenType type;
    String lexeme{};
    String literal{};
    int line{};
};

#endif