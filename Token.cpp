#include "Token.h"

Token::Token(TokenType type, String lexeme, String literal, int line) : type(type), lexeme(std::move(lexeme)), literal(std::move(literal)), line(line) {

}

String Token::toString() const {
    return std::to_string(line) + " " + type._to_string() + " " + lexeme + " " + literal;
}