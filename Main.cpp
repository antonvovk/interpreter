#include "Scanner.h"
#include "Printer.h"
#include "Parser.h"
#include "Interpreter.h"

void test(const String &line) {
    Scanner scanner(line);
    Array<Token> tokens = scanner.scanTokens();

    Parser parser(tokens);
    Array<std::shared_ptr<Statement>> statements = parser.parse();

    if (statements.empty()) {
        return;
    }

    Interpreter interpreter;
    interpreter.interpret(statements);
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