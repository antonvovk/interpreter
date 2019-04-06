#include "Scanner.h"
#include "Token.h"
#include "Printer.h"
#include "Expression.h"

void tokenize(const String& line) {
    Scanner scanner(line);
    Array<Token> tokens = scanner.scanTokens();

    for (const auto &token : tokens) {
        std::cout << token.toString() << '\n';
    }
}

int main() {
    String line;
    File file("Test.txt");

    if (file.is_open()) {
        while (getline(file, line)) {
            tokenize(line);
        }

        file.close();
    }
    else {
        std::cout << "Unable to open file!" << '\n';
    }


    Expression *expression = new Binary(new Unary(*new Token(TokenType::MINUS, "-", "", 1), new Literal("123")), *new Token(TokenType::STAR, "*", "", 1), new Grouping(new Literal("45.67")));

    Printer printer;
    std::cout << printer.print(expression);

    return 0;
}