#include "Scanner.h"
#include "Token.h"
#include "Printer.h"
#include "Expression.h"
#include "Parser.h"

void test(const String &line) {
    Scanner scanner(line);
    Array<Token> tokens = scanner.scanTokens();

    for (const auto &token : tokens) {
        std::cout << token.toString() << '\n';
    }

    Parser parser(tokens);
    Expression* expression = parser.parse();

    if (expression == nullptr) {
        return;
    }

    Printer printer;
    std::cout << printer.print(expression) << '\n';

    Expression *expression2 = new Binary(new Unary(*new Token(TokenType::MINUS, "-", "", 1), new Literal("123")), *new Token(TokenType::STAR, "*", "", 1), new Grouping(new Literal("45.67")));

    std::cout << printer.print(expression2);
}

int main() {
    String line;
    File file("Test.txt");

    if (file.is_open()) {
        while (getline(file, line)) {
            test(line);
        }

        file.close();
    }
    else {
        std::cout << "Unable to open file!" << '\n';
    }

    return 0;
}