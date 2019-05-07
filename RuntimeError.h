#ifndef RUNTIMEERROR_H
#define RUNTIMEERROR_H

#include "Utils.h"
#include "Token.h"

class RuntimeError : public Exception {
public:
    RuntimeError(const Token& token, const String& message) {
        std::cout << message << "; At line" << token.toString();
    }
private:
    Token token;
};

#endif
