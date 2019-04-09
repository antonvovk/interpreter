#ifndef RUNTIMEERROR_H
#define RUNTIMEERROR_H

#include "Utils.h"
#include "Token.h"

class RuntimeError : public Exception {
public:
    RuntimeError(Token token, const String& message) {
        std::cout << message;
        this->token = std::move(token);
    }
private:
    Token token;
};

#endif
