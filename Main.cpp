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
    File file("Test.txt");

    if (file.is_open()) {
        std::string str((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
        test(str);
        file.close();
    }
    else {
        std::cout << "Unable to open file!" << '\n';
    }

    return 0;
}