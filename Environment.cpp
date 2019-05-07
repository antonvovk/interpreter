#include "Environment.h"

Environment::Environment() : enclosing(nullptr) {

}

void Environment::define(const String& name, const Object& value) const {
    if (values.find(name) != values.end()) {
        values[name] = value;
    }
    else {
        values.insert(std::make_pair(name, value));
    }

}

Object Environment::get(const Token& name) const {
    if (values.find(name.Lexeme()) != values.end()) {
        return values.at(name.Lexeme());
    }

    if (enclosing != nullptr) {
        return enclosing->get(name);
    }


    throw RuntimeError(name, "Undefined variable '" + name.Lexeme() + "'.");
}

void Environment::assign(Token name, Object value) const {
    if (values.find(name.Lexeme()) != values.end()) {
        values[name.Lexeme()] = value;
        return;
    }

    if (enclosing != nullptr) {
        enclosing->assign(name, value);
        return;
    }

    throw RuntimeError(name, "Undefined variable '" + name.Lexeme() + "'.");
}

void Environment::assign(String name, Object value) const {
    for (auto &i : values) {
        if (objectToString(i.second) == name) {
            i.second = value;
            break;
        }
    }

    //throw RuntimeError(name, String("Undefined variable ") + name + String("."));
}

void Environment::deleteVar(String name) {
    for (auto &i : values) {
        if (objectToString(i.second) == name) {
            values.erase(i.first);
            break;
        }
    }
}