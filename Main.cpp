#include "Scanner.h"
#include "Token.h"

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

    return 0;
}