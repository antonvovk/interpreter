#include "Scanner.h"
#include "Printer.h"
#include "Parser.h"
#include "Interpreter.h"

void test(const String &line) {
    Scanner scanner(line);
    Array<Token> tokens = scanner.scanTokens();

    for (const auto &token : tokens) {
        std::cout << token.toString() << '\n';
    }

    Parser parser(tokens);
    std::shared_ptr<Expression> expression = parser.parse();

    if (expression == nullptr) {
        return;
    }

    Printer printer;
    std::cout << printer.print(expression) << '\n';

    Interpreter interpreter;
    interpreter.interpret(expression);
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