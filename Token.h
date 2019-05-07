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

    IDENTIFIER, STRING, IO_FILE,
    INT, FLOAT, BOOL, CHAR,

    AND, ELSE, FALSE, FUN, FOR, IF,
    NIL, OR, TRUE, WHILE,

    COPY, MOVE, REMOVE, PRINT,
    FIND, FIND_SAME,

    EOFL, UNDEFINED
)

interface IToken {
public:
    virtual String toString() const = 0;
    virtual TokenType Type() const = 0;
    virtual String Lexeme() const = 0;
    virtual Object Literal() const = 0;
    virtual int Line() const = 0;
};

class Token : public IToken {
public:
    explicit Token();
    explicit Token(TokenType type, String lexeme, Object literal, int line);
    String toString() const override;
    TokenType Type() const override;
    String Lexeme() const override;
    Object Literal() const override;
    int Line() const override;
private:
    TokenType type;
    String lexeme{};
    Object literal{};
    int line{};
};

#endif
