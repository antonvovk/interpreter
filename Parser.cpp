#include "Parser.h"

Parser::Parser(Array<Token> tokens) : tokens(std::move(tokens)) {

}

Expression *Parser::parse() {
    try {
        return expression();
    }
    catch (ParseError& error) {
        return nullptr;
    }
}

Expression* Parser::expression() {
    return equality();
}

Expression* Parser::equality() {
    Expression* expr = comparison();

    while (match({TokenType::BANG_EQUAL, TokenType::EQUAL_EQUAL})) {
        Token operatr = previous();
        Expression* right = comparison();
        expr = new Binary(expr, operatr, right);
    }

    return expr;
}

bool Parser::match(std::initializer_list<TokenType> types) {
    for (TokenType type : types) {
        if (check(type)) {
            advance();
            return true;
        }
    }

    return false;
}

bool Parser::check(TokenType type) const {
    if (isAtEnd()) {
        return false;
    }

    return peek().Type() == type;
}

Token Parser::advance() {
    if (!isAtEnd()) {
        ++current;
    }

    return previous();
}

bool Parser::isAtEnd() const {
    return peek().Type() == TokenType::_from_string("EOFL");
}

Token Parser::peek() const {
    return tokens.at(current);
}

Token Parser::previous() const {
    return tokens.at(current - 1);
}

Expression* Parser::comparison() {
    Expression* expr = addition();

    while (match({TokenType::GREATER, TokenType::GREATER_EQUAL, TokenType::LESS, TokenType::LESS_EQUAL})) {
        Token operatr = previous();
        Expression* right = addition();
        expr = new Binary(expr, operatr, right);
    }

    return expr;
}

Expression* Parser::addition() {
    Expression* expr = multiplication();

    while (match({TokenType::MINUS, TokenType::PLUS})) {
        Token operatr = previous();
        Expression* right = multiplication();
        expr = new Binary(expr, operatr, right);
    }

    return expr;
}

Expression* Parser::multiplication() {
    Expression* expr = unary();

    while (match({TokenType::SLASH, TokenType::STAR})) {
        Token operatr = previous();
        Expression* right = unary();
        expr = new Binary(expr, operatr, right);
    }

    return expr;
}

Expression *Parser::unary() {
    if (match({TokenType::BANG, TokenType::MINUS})) {
        Token operatr = previous();
        Expression* right = unary();
        return new Unary(operatr, right);
    }

    return primary();
}

Expression *Parser::primary() {
    if (match({TokenType::FALSE})) {
        return new Literal("false");
    }

    if (match({TokenType::TRUE})) {
        return new Literal("true");
    }

    if (match({TokenType::NIL})) {
        return new Literal("null");
    }

    if (match({TokenType::NUMBER, TokenType::STRING})) {
        return new Literal(previous().Literal());
    }

    if (match({TokenType::LEFT_PAREN})) {
        Expression* expr = expression();
        consume(TokenType::RIGHT_PAREN, "Expect ')' after expression.");
        return new Grouping(expr);
    }

    throw error(peek(), "Expect expression.");
}

Token Parser::consume(TokenType type, const String& message) {
    if (check(type)) {
        return advance();
    }

    throw error(peek(), message);
}

ParseError Parser::error(const Token& token, const String& message) const {
    if (token.Type() == TokenType::_from_string("EOFL")) {
        std::cout << token.Line() << " at end" << message;
    }
    else {
        std::cout << token.Line() << " at '" << token.Lexeme() << "'" << message;
    }

    return *new ParseError();
}

void Parser::synchronize() {
    advance();

    while (!isAtEnd()) {
        if (previous().Type() == TokenType::_from_string("SEMICOLON")) return;

        switch (peek().Type()) {
            case TokenType::CLASS:
            case TokenType::FUN:
            case TokenType::VAR:
            case TokenType::FOR:
            case TokenType::IF:
            case TokenType::WHILE:
            case TokenType::PRINT:
            case TokenType::RETURN:
                return;
        }

        advance();
    }
}