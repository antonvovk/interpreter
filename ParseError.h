#ifndef PARSEERROR_H
#define PARSEERROR_H

#include "Utils.h"

class ParseError : public Exception {
public:
    explicit ParseError() = default;
};

#endif