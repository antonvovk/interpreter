#include "Scanner.h"

int Scanner::line = 1;

Map<String, TokenType> Scanner::keywords = {
        Pair<String, TokenType> ("and", TokenType::AND),
        Pair<String, TokenType> ("else", TokenType::ELSE),
        Pair<String, TokenType> ("false", TokenType::FALSE),
        Pair<String, TokenType> ("for", TokenType::FOR),
        Pair<String, TokenType> ("fun", TokenType::FUN),
        Pair<String, TokenType> ("if", TokenType::IF),
        Pair<String, TokenType> ("nil", TokenType::NIL),
        Pair<String, TokenType> ("or", TokenType::OR),
        Pair<String, TokenType> ("print", TokenType::PRINT),
        Pair<String, TokenType> ("move", TokenType::MOVE),
        Pair<String, TokenType> ("copy", TokenType::COPY),
        Pair<String, TokenType> ("remove", TokenType::REMOVE),
        Pair<String, TokenType> ("find", TokenType::FIND),
        Pair<String, TokenType> ("find_same", TokenType::FIND_SAME),
        Pair<String, TokenType> ("true", TokenType::TRUE),
        Pair<String, TokenType> ("File", TokenType::IO_FILE),
        Pair<String, TokenType> ("Int", TokenType::INT),
        Pair<String, TokenType> ("Float", TokenType::FLOAT),
        Pair<String, TokenType> ("Bool", TokenType::BOOL),
        Pair<String, TokenType> ("Char", TokenType::CHAR),
        Pair<String, TokenType> ("String", TokenType::STRING),
        Pair<String, TokenType> ("while", TokenType::WHILE)
};

Scanner::Scanner(String source) : source(std::move(source)) {

}

Array<Token> Scanner::scanTokens() {
    while (!isAtEnd()) {
        start = current;
        scanToken();
    }

    tokens.push_back(Token(TokenType::EOFL, "", String(""), ++line));
    return tokens;
}

bool Scanner::isAtEnd() const {
    return current >= source.length();
}

void Scanner::scanToken() {
    char c = advance();
    switch (c) {
        case '(': addToken(TokenType::LEFT_PAREN); break;
        case ')': addToken(TokenType::RIGHT_PAREN); break;
        case '{': addToken(TokenType::LEFT_BRACE); break;
        case '}': addToken(TokenType::RIGHT_BRACE); break;
        case ',': addToken(TokenType::COMMA); break;
        case '.': addToken(TokenType::DOT); break;
        case '-': addToken(TokenType::MINUS); break;
        case '+': addToken(TokenType::PLUS); break;
        case ';': addToken(TokenType::SEMICOLON); break;
        case '*': addToken(TokenType::STAR); break;
        case '!': addToken(match('=') ? TokenType::BANG_EQUAL : TokenType::BANG); break;
        case '=': addToken(match('=') ? TokenType::EQUAL_EQUAL : TokenType::EQUAL); break;
        case '<': addToken(match('=') ? TokenType::LESS_EQUAL : TokenType::LESS); break;
        case '>': addToken(match('=') ? TokenType::GREATER_EQUAL : TokenType::GREATER); break;
        case '/':
            if (match('/')) {
                while (peek() != '\n' && !isAtEnd()) advance();
            }
            else {
                addToken(TokenType::SLASH);
            }
            break;

        case ' ':
        case '\r':
        case '\t':
            break;

        case '\n':
            ++line;
            break;

        case '"': string(); break;

        case 'o':
            if (peek() == 'r') {
                addToken(TokenType::OR);
            }
            break;

        default:
            if (isDigit(c)) {
                number();
            }
            else if (isAlpha(c)) {
                identifier();
            }
            else {
                std::cout << std::to_string(line) << " Unexpected character.";
            }
            break;
    }
}

char Scanner::advance() {
    ++current;
    return source.at(current - 1);
}

void Scanner::addToken(TokenType type) {
    addToken(type, String(""));
}

void Scanner::addToken(TokenType type, Object literal) {
    String text;

    if (type == TokenType::_from_string("OR")) {
        ++current;
        text = source.substr(start, current - start);
    }
    else {
        text = source.substr(start, current - start);
    }


    tokens.push_back(Token(type, text, std::move(literal), line));
}

bool Scanner::match(char expected) {
    if (isAtEnd() || source.at(current) != expected) {
        return false;
    }

    ++current;
    return true;
}

char Scanner::peek() {
    if (isAtEnd()) {
        return '\0';
    }

    return source.at(current);
}

void Scanner::string() {
    while (peek() != '"' && !isAtEnd()) {
        if (peek() == '\n') {
            ++line;
        }

        advance();
    }

    if (isAtEnd()) {
        std::cout << std::to_string(line) << "Unterminated string.";
        return;
    }

    advance();

    String value = source.substr(start + 1, current - start - 2);
    if (value.size() == 1) {
        addToken(TokenType::CHAR, value[0]);
    }
    else {
        addToken(TokenType::STRING, value);
    }
}

bool Scanner::isDigit(char c) {
    return c >= '0' && c <= '9';
}

void Scanner::number() {
    while (isDigit(peek())) {
        advance();
    }

    if (peek() == '.' && isDigit(peekNext())) {
        advance();

        while (isDigit(peek())) {
            advance();
        }
    }
    String s = source.substr(start, current - start);

    if (s.find('.') != String::npos) {
        addToken(TokenType::FLOAT, (float)std::stof(source.substr(start, current - start)));
    }
    else {
        addToken(TokenType::INT, (int)std::stoi(source.substr(start, current - start)));
    }

}

char Scanner::peekNext() {
    if (current + 1 >= source.length()) {
        return '\0';
    }

    return source.at(current + 1);
}

void Scanner::identifier() {
    while (isAlphaNumeric(peek())) {
        advance();
    }

    String text = source.substr(start, current - start);

    TokenType type = TokenType::IDENTIFIER;

    if (keywords.find(text) != keywords.end()) {
        type = keywords.at(text);
    }

    addToken(type);
}

bool Scanner::isAlpha(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_';
}

bool Scanner::isAlphaNumeric(char c) {
    return isAlpha(c) || isDigit(c);
}