#ifndef SCANNER_H
#define SCANNER_H

#include "Utils.h"
#include "Token.h"

interface IScanner {
public:
    virtual Array<Token> scanTokens() = 0;
};

class Scanner : public IScanner {
public:
    explicit Scanner(String source);
    Array<Token> scanTokens() override;

private:
    bool isAtEnd() const;
    void scanToken();
    char advance();
    void addToken(TokenType type);
    void addToken(TokenType type, String literal);
    bool match(char expected);
    char peek();
    void string();
    static bool isDigit(char c);
    void number();
    char peekNext();
    void identifier();
    static bool isAlpha(char c);
    static bool isAlphaNumeric(char c);

    String source{};
    Array<Token> tokens{};
    int start{};
    int current{};
    static int line;
    static Map<String, TokenType> keywords;
};

#endif