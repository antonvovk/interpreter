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
    void define(const String& name, const Object& value) const override;
    Object get(const Token& name) const override;
    void assign(Token name, Object value) const override;
private:
    static Map<String, Object> values;
};

#endif