#include "Environment.h"

Map<String, Object> Environment::values = {};

void Environment::define(const String& name, const Object& value) const {
    values.insert(std::make_pair(name, value));
}

Object Environment::get(const Token& name) const {
    if (values.find(name.Lexeme()) != values.end()) {
        return values.at(name.Lexeme());
    }

    throw RuntimeError(name, "Undefined variable '" + name.Lexeme() + "'.");
}
