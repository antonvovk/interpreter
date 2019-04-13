#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include "Utils.h"
#include "Token.h"
#include "RuntimeError.h"

interface IEnvironment {
public:
    virtual void define(const String& name, const Object& value) const = 0;
    virtual Object get(const Token& name) const = 0;
    virtual void assign(Token name, Object value) const = 0;
};

class Environment : public IEnvironment {
public:
    explicit Environment();
    void define(const String& name, const Object& value) const override;
    Object get(const Token& name) const override;
    void assign(Token name, Object value) const override;
private:
    mutable Map<String, Object> values{};
    std::shared_ptr<Environment> enclosing{};
};

#endif