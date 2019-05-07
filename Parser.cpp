#include "Parser.h"

Parser::Parser(Array<Token> tokens) : tokens(std::move(tokens)) {

}

Array<std::shared_ptr<Statement>> Parser::parse() {
    Array<std::shared_ptr<Statement>> statements;

    while (!isAtEnd()) {
        statements.push_back(declaration());
    }

    return statements;
}

std::shared_ptr<Statement> Parser::statement() {
    if (match({TokenType::IF})) {
        return ifStatement();
    }

    if (match({TokenType::PRINT})) {
        return printStatement();
    }

    if (match({TokenType::WHILE})) {
        return whileStatement();
    }

    if (match({TokenType::MOVE})) {
        return moveStatement();
    }

    if (match({TokenType::COPY})) {
        return copyStatement();
    }

    if (match({TokenType::REMOVE})) {
        return removeStatement();
    }

    if (match({TokenType::FIND})) {
        return findStatement();
    }

    if (match({TokenType::FIND_SAME})) {
        return find_sameStatement();
    }


    if (match({TokenType::LEFT_BRACE})) {
        return std::make_shared<Block> (block());
    }

    return expressionStatement();
}


std::shared_ptr<Statement> Parser::whileStatement() {
    consume(TokenType::LEFT_PAREN, "Expect '(' after 'while'.");
    std::shared_ptr<Expression> condition = expression();
    consume(TokenType::RIGHT_PAREN, "Expect ')' after condition.");
    std::shared_ptr<Statement> body = statement();

    return std::make_shared<While> (condition, body);
}

std::shared_ptr<Statement> Parser::ifStatement() {
    consume(TokenType::LEFT_PAREN, "Expect '(' after 'if'.");
    std::shared_ptr<Expression> condition = expression();
    consume(TokenType::RIGHT_PAREN, "Expect ')' after if condition.");

    std::shared_ptr<Statement> thenBranch = statement();
    std::shared_ptr<Statement> elseBranch = nullptr;
    if (match({TokenType::ELSE})) {
        elseBranch = statement();
    }

    return std::make_shared<If> (condition, thenBranch, elseBranch);
}

Array<std::shared_ptr<Statement>> Parser::block() {
    Array<std::shared_ptr<Statement>> statements;

    while (!check(TokenType::RIGHT_BRACE) && !isAtEnd()) {
        statements.push_back(declaration());
    }

    consume(TokenType::RIGHT_BRACE, "Expect '}' after block.");
    return statements;
}

std::shared_ptr<Statement> Parser::declaration() {
    if (match({TokenType::FLOAT})) {
        return floatVarDeclaration();
    }
    if (match({TokenType::INT})) {
        return intVarDeclaration();
    }
    if (match({TokenType::IO_FILE})) {
        return fileVarDeclaration();
    }
    if (match({TokenType::BOOL})) {
        return boolVarDeclaration();
    }
    if (match({TokenType::CHAR})) {
        return charVarDeclaration();
    }
    if (match({TokenType::STRING})) {
        return stringVarDeclaration();
    }

    return statement();
}

std::shared_ptr<Statement> Parser::floatVarDeclaration() {
    Token name = consume(TokenType::IDENTIFIER, "Expect variable name.");

    std::shared_ptr<Expression> initializer = nullptr;
    if (match({TokenType::EQUAL})) {
        initializer = expression();
    }

    consume(TokenType::SEMICOLON, "Expect ';' after variable declaration.");

    if (typeid(*initializer).name() == typeid(Literal).name()) {
        if ((std::dynamic_pointer_cast<Literal> (initializer)).get()->Value().type() != typeid(float)) {
            error(name, "Cant assing");
            exit(1);
        }
    }

    return std::make_shared<Var>(name, initializer, "Float");
}

std::shared_ptr<Statement> Parser::intVarDeclaration() {
    Token name = consume(TokenType::IDENTIFIER, "Expect variable name.");

    std::shared_ptr<Expression> initializer = nullptr;
    if (match({TokenType::EQUAL})) {
        initializer = expression();
    }

    consume(TokenType::SEMICOLON, "Expect ';' after variable declaration.");

    if (typeid(*initializer).name() == typeid(Literal).name()) {
        if ((std::dynamic_pointer_cast<Literal> (initializer)).get()->Value().type() != typeid(int)) {
            error(name, "Cant assing");
            exit(1);
        }
    }

    return std::make_shared<Var>(name, initializer, "Int");
}

std::shared_ptr<Statement> Parser::stringVarDeclaration() {
    Token name = consume(TokenType::IDENTIFIER, "Expect variable name.");

    std::shared_ptr<Expression> initializer = nullptr;
    if (match({TokenType::EQUAL})) {
        initializer = expression();
    }

    consume(TokenType::SEMICOLON, "Expect ';' after variable declaration.");

    if (typeid(*initializer).name() == typeid(Literal).name()) {
        if ((std::dynamic_pointer_cast<Literal> (initializer)).get()->Value().type() != typeid(String)) {
            error(name, "Cant assing");
            exit(1);
        }
    }

    return std::make_shared<Var>(name, initializer, "String");
}

std::shared_ptr<Statement> Parser::charVarDeclaration() {
    Token name = consume(TokenType::IDENTIFIER, "Expect variable name.");

    std::shared_ptr<Expression> initializer = nullptr;
    if (match({TokenType::EQUAL})) {
        initializer = expression();
    }

    consume(TokenType::SEMICOLON, "Expect ';' after variable declaration.");

    if (typeid(*initializer).name() == typeid(Literal).name()) {
        if ((std::dynamic_pointer_cast<Literal> (initializer)).get()->Value().type() != typeid(char)) {
            error(name, "Cant assing");
            exit(1);
        }
    }

    return std::make_shared<Var>(name, initializer, "Char");
}

std::shared_ptr<Statement> Parser::fileVarDeclaration() {
    Token name = consume(TokenType::IDENTIFIER, "Expect variable name.");

    std::shared_ptr<Expression> initializer = nullptr;
    if (match({TokenType::EQUAL})) {
        initializer = expression();
    }

    consume(TokenType::SEMICOLON, "Expect ';' after variable declaration.");

    if (typeid(*initializer).name() == typeid(Literal).name()) {
        if ((std::dynamic_pointer_cast<Literal> (initializer)).get()->Value().type() != typeid(String)) {
            error(name, "Cant assing");
            exit(1);
        }
    }

    return std::make_shared<Var>(name, initializer, "File");
}

std::shared_ptr<Statement> Parser::boolVarDeclaration() {
    Token name = consume(TokenType::IDENTIFIER, "Expect variable name.");

    std::shared_ptr<Expression> initializer = nullptr;
    if (match({TokenType::EQUAL})) {
        initializer = expression();
    }

    consume(TokenType::SEMICOLON, "Expect ';' after variable declaration.");

    if (typeid(*initializer).name() == typeid(Literal).name()) {
        if ((std::dynamic_pointer_cast<Literal> (initializer)).get()->Value().type() != typeid(bool)) {
            error(name, "Cant assing");
            exit(1);
        }
    }

    return std::make_shared<Var>(name, initializer, "Bool");
}

std::shared_ptr<Statement> Parser::printStatement() {
    std::shared_ptr<Expression> value = expression();
    consume(TokenType::SEMICOLON, "Expect ';' after value.");

    return std::make_shared<Print>(value);
}

std::shared_ptr<Statement> Parser::moveStatement() {
    std::shared_ptr<Expression> value1 = expression();
    std::shared_ptr<Expression> value2 = expression();
    consume(TokenType::SEMICOLON, "Expect ';' after value.");

    return std::make_shared<Move>(value1, value2);
}

std::shared_ptr<Statement> Parser::copyStatement() {
    std::shared_ptr<Expression> value1 = expression();
    std::shared_ptr<Expression> value2 = expression();
    consume(TokenType::SEMICOLON, "Expect ';' after value.");

    return std::make_shared<Copy>(value1, value2);
}

std::shared_ptr<Statement> Parser::removeStatement() {
    std::shared_ptr<Expression> value = expression();
    consume(TokenType::SEMICOLON, "Expect ';' after value.");

    return std::make_shared<Remove>(value);
}

std::shared_ptr<Statement> Parser::findStatement() {
    std::shared_ptr<Expression> value = expression();
    consume(TokenType::SEMICOLON, "Expect ';' after value.");

    return std::make_shared<Find>(value);
}

std::shared_ptr<Statement> Parser::find_sameStatement() {
    std::shared_ptr<Expression> value = expression();
    consume(TokenType::SEMICOLON, "Expect ';' after value.");

    return std::make_shared<FindSame>(value);
}

std::shared_ptr<Statement> Parser::expressionStatement() {
    std::shared_ptr<Expression> expr = expression();
    consume(TokenType::SEMICOLON, "Expect ';' after expression.");

    return std::make_shared<ExpressionStmnt>(expr);
}

std::shared_ptr<Expression> Parser::expression() {
    return assignment();
}

std::shared_ptr<Expression> Parser::assignment() {
    std::shared_ptr<Expression>  expr = OR();

    if (match({TokenType::EQUAL})) {
        Token equals = previous();
        std::shared_ptr<Expression> value = assignment();

        if (typeid(*expr).name() == typeid(Variable).name()) {
            Token name = (std::dynamic_pointer_cast<Variable> (expr))->Name();
            return std::make_shared<Assign> (name, value);
        }

        error(equals, "Invalid assignment target.");
        exit(1);
    }

    return expr;
}

std::shared_ptr<Expression> Parser::OR() {
    std::shared_ptr<Expression> expr = AND();

    while (match({TokenType::OR})) {
        Token operatr = previous();
        std::shared_ptr<Expression> right = AND();
        expr = std::make_shared<Logical> (expr, operatr, right);
    }

    return expr;
}

std::shared_ptr<Expression> Parser::AND() {
    std::shared_ptr<Expression> expr = equality();

    while (match({TokenType::AND})) {
        Token operatr = previous();
        std::shared_ptr<Expression> right = equality();
        expr = std::make_shared<Logical> (expr, operatr, right);
    }

    return expr;
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

    if (match({TokenType::STRING, TokenType::INT, TokenType::FLOAT, TokenType::CHAR})) {
        return std::make_shared<Literal>(previous().Literal());
    }
    if (match({TokenType::IDENTIFIER})) {
        return std::make_shared<Variable> (previous());
    }
    if (match({TokenType::LEFT_PAREN})) {
        std::shared_ptr<Expression> expr = expression();
        consume(TokenType::RIGHT_PAREN, "Expect ')' after expression.");
        return std::make_shared<Grouping> (expr);
    }

    error(peek(), "Expect expression.");
    exit(1);
}

Token Parser::consume(TokenType type, const String& message) {
    if (check(type)) {
        return advance();
    }

    error(peek(), message);
    exit(1);
}

void Parser::error(const Token& token, const String& message) const {
    if (token.Type() == TokenType::_from_string("EOFL")) {
        std::cout << token.Line() << " at end" << message;
    }
    else {
        std::cout << token.Line() << " at '" << token.Lexeme() << "'" << message;
    }

    exit(1);
}