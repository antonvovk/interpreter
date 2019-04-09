#include "Parser.h"

Parser::Parser(Array<Token> tokens) : tokens(std::move(tokens)) {

}

std::shared_ptr<Expression> Parser::parse() {
    try {
        return expression();
    }
    catch (ParseError& error) {
        return nullptr;
    }
}

std::shared_ptr<Expression> Parser::expression() {
    return equality();
}

std::shared_ptr<Expression> Parser::equality() {
    std::shared_ptr<Expression> expr = comparison();

    while (match({TokenType::BANG_EQUAL, TokenType::EQUAL_EQUAL})) {
        Token operatr = previous();
        std::shared_ptr<Expression> right = comparison();
        expr = std::make_shared<Binary>(expr, operatr, right);
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

std::shared_ptr<Expression> Parser::comparison() {
    std::shared_ptr<Expression> expr = addition();

    while (match({TokenType::GREATER, TokenType::GREATER_EQUAL, TokenType::LESS, TokenType::LESS_EQUAL})) {
        Token operatr = previous();
        std::shared_ptr<Expression> right = addition();
        expr = std::make_shared<Binary>(expr, operatr, right);
    }

    return expr;
}

std::shared_ptr<Expression> Parser::addition() {
    std::shared_ptr<Expression> expr = multiplication();

    while (match({TokenType::MINUS, TokenType::PLUS})) {
        Token operatr = previous();
        std::shared_ptr<Expression> right = multiplication();
        expr = std::make_shared<Binary>(expr, operatr, right);
    }

    return expr;
}

std::shared_ptr<Expression> Parser::multiplication() {
    std::shared_ptr<Expression> expr = unary();

    while (match({TokenType::SLASH, TokenType::STAR})) {
        Token operatr = previous();
        std::shared_ptr<Expression> right = unary();
        expr = std::make_shared<Binary>(expr, operatr, right);
    }

    return expr;
}

std::shared_ptr<Expression> Parser::unary() {
    if (match({TokenType::BANG, TokenType::MINUS})) {
        Token operatr = previous();
        std::shared_ptr<Expression> right = unary();
        return std::make_shared<Unary>(operatr, right);
    }

    return primary();
}

std::shared_ptr<Expression> Parser::primary() {
    if (match({TokenType::FALSE})) {
        return std::make_shared<Literal>(false);
    }

    if (match({TokenType::TRUE})) {
        return std::make_shared<Literal>(true);
    }

    if (match({TokenType::NIL})) {
        return std::make_shared<Literal>(nullptr);
    }

    if (match({TokenType::NUMBER, TokenType::STRING})) {
        return std::make_shared<Literal>(previous().Literal());
    }

    if (match({TokenType::LEFT_PAREN})) {
        std::shared_ptr<Expression> expr = expression();
        consume(TokenType::RIGHT_PAREN, "Expect ')' after expression.");
        return std::make_shared<Grouping>(expr);
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

    return ParseError();
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