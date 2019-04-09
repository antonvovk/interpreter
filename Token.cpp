#include "Token.h"

Token::Token() : type(TokenType::UNDEFINED) {

}

Token::Token(TokenType type, String lexeme, Object literal, int line) : type(type), lexeme(std::move(lexeme)), literal(std::move(literal)), line(line) {

}

String Token::toString() const {
    return std::to_string(this->line) + " " + this->type._to_string() + " " + this->lexeme + " " + objectToString(this->literal);
}

TokenType Token::Type() const {
    return this->type;
}

String Token::Lexeme() const {
    return this->lexeme;
}

Object Token::Literal() const {
    return this->literal;
}

int Token::Line() const {
    return this->line;
}