#include <utility>

#include <utility>

#include <utility>

#include "Interpreter.h"

void Interpreter::interpret(Array<std::shared_ptr<Statement>> statements) {
    try {
        for (const std::shared_ptr<Statement>& statement : statements) {
            execute(statement);
        }
    }
    catch (RuntimeError &error) {
        std::cout << error.what();
        return;
    }
}

Object Interpreter::visit(Assign &expr) {
    Object value = evaluate(expr.Value());

    if (environment.get(expr.Name()).type() != value.type()) {
        RuntimeError(expr.Name(), "Can not do assigment because of uncorrect types.");
        exit(0);
    }

    environment.assign(expr.Name(), value);
    return value;
}

Object Interpreter::visit(Binary &expr) {
    Object left = evaluate(expr.Left());
    Object right = evaluate(expr.Right());

    switch (expr.Operatr().Type()) {
        case TokenType::GREATER:
            if (right.type() == typeid(short)) {
                return std::any_cast<short>(left) > std::any_cast<short>(right);
            }
            else if (right.type() == typeid(int)) {
                return std::any_cast<int>(left) > std::any_cast<int>(right);
            }
            else if (right.type() == typeid(long)) {
                return std::any_cast<long>(left) > std::any_cast<long>(right);
            }
            else if (right.type() == typeid(long long)) {
                return std::any_cast<long long>(left) > std::any_cast<long long>(right);
            }
            else if (right.type() == typeid(float)) {
                return std::any_cast<float>(left) > std::any_cast<float>(right);
            }
            else if (right.type() == typeid(double)) {
                return std::any_cast<double>(left) > std::any_cast<double>(right);
            }
            else if (right.type() == typeid(long double)) {
                return std::any_cast<long double>(left) > std::any_cast<long double>(right);
            }
            else if (right.type() == typeid(String)) {
                return std::any_cast<String>(left) > std::any_cast<String>(right);
            }

        case TokenType::GREATER_EQUAL:
            if (right.type() == typeid(short)) {
                return std::any_cast<short>(left) >= std::any_cast<short>(right);
            }
            else if (right.type() == typeid(int)) {
                return std::any_cast<int>(left) >= std::any_cast<int>(right);
            }
            else if (right.type() == typeid(long)) {
                return std::any_cast<long>(left) >= std::any_cast<long>(right);
            }
            else if (right.type() == typeid(long long)) {
                return std::any_cast<long long>(left) >= std::any_cast<long long>(right);
            }
            else if (right.type() == typeid(float)) {
                return std::any_cast<float>(left) >= std::any_cast<float>(right);
            }
            else if (right.type() == typeid(double)) {
                return std::any_cast<double>(left) >= std::any_cast<double>(right);
            }
            else if (right.type() == typeid(long double)) {
                return std::any_cast<long double>(left) >= std::any_cast<long double>(right);
            }
            else if (right.type() == typeid(String)) {
                return std::any_cast<String>(left) >= std::any_cast<String>(right);
            }

        case TokenType::LESS:
            if (right.type() == typeid(short)) {
                return std::any_cast<short>(left) < std::any_cast<short>(right);
            }
            else if (right.type() == typeid(int)) {
                return std::any_cast<int>(left) < std::any_cast<int>(right);
            }
            else if (right.type() == typeid(long)) {
                return std::any_cast<long>(left) < std::any_cast<long>(right);
            }
            else if (right.type() == typeid(long long)) {
                return std::any_cast<long long>(left) < std::any_cast<long long>(right);
            }
            else if (right.type() == typeid(float)) {
                return std::any_cast<float>(left) < std::any_cast<float>(right);
            }
            else if (right.type() == typeid(double)) {
                return std::any_cast<double>(left) < std::any_cast<double>(right);
            }
            else if (right.type() == typeid(long double)) {
                return std::any_cast<long double>(left) < std::any_cast<long double>(right);
            }
            else if (right.type() == typeid(String)) {
                return std::any_cast<String>(left) < std::any_cast<String>(right);
            }

        case TokenType::LESS_EQUAL:
            if (right.type() == typeid(short)) {
                return std::any_cast<short>(left) <= std::any_cast<short>(right);
            }
            else if (right.type() == typeid(int)) {
                return std::any_cast<int>(left) <= std::any_cast<int>(right);
            }
            else if (right.type() == typeid(long)) {
                return std::any_cast<long>(left) <= std::any_cast<long>(right);
            }
            else if (right.type() == typeid(long long)) {
                return std::any_cast<long long>(left) <= std::any_cast<long long>(right);
            }
            else if (right.type() == typeid(float)) {
                return std::any_cast<float>(left) <= std::any_cast<float>(right);
            }
            else if (right.type() == typeid(double)) {
                return std::any_cast<double>(left) <= std::any_cast<double>(right);
            }
            else if (right.type() == typeid(long double)) {
                return std::any_cast<long double>(left) <= std::any_cast<long double>(right);
            }
            else if (right.type() == typeid(String)) {
                return std::any_cast<String>(left) <= std::any_cast<String>(right);
            }

        case TokenType::MINUS:
            checkNumberOperands(expr.Operatr(), left, right);
            if (right.type() == typeid(short)) {
                return std::any_cast<short>(left) - std::any_cast<short>(right);
            }
            else if (right.type() == typeid(int)) {
                return std::any_cast<int>(left) - std::any_cast<int>(right);
            }
            else if (right.type() == typeid(long)) {
                return std::any_cast<long>(left) - std::any_cast<long>(right);
            }
            else if (right.type() == typeid(long long)) {
                return std::any_cast<long long>(left) - std::any_cast<long long>(right);
            }
            else if (right.type() == typeid(float)) {
                return std::any_cast<float>(left) - std::any_cast<float>(right);
            }
            else if (right.type() == typeid(double)) {
                return std::any_cast<double>(left) - std::any_cast<double>(right);
            }
            else if (right.type() == typeid(long double)) {
                return std::any_cast<long double>(left) - std::any_cast<long double>(right);
            }

        case TokenType::PLUS:
            if (left.type() == typeid(int) && right.type() == typeid(String)) {
                return std::to_string(std::any_cast<int>(left)) + std::any_cast<String >(right);
            }
            else if (right.type() == typeid(short)) {
                return std::any_cast<short>(left) + std::any_cast<short>(right);
            }
            else if (right.type() == typeid(int)) {
                return std::any_cast<int>(left) + std::any_cast<int>(right);
            }
            else if (right.type() == typeid(long)) {
                return std::any_cast<long>(left) + std::any_cast<long>(right);
            }
            else if (right.type() == typeid(long long)) {
                return std::any_cast<long long>(left) + std::any_cast<long long>(right);
            }
            else if (right.type() == typeid(float)) {
                return std::any_cast<float>(left) + std::any_cast<float>(right);
            }
            else if (right.type() == typeid(double)) {
                return std::any_cast<double>(left) + std::any_cast<double>(right);
            }
            else if (right.type() == typeid(long double)) {
                return std::any_cast<long double>(left) + std::any_cast<long double>(right);
            }
            else if (right.type() == typeid(String)) {
                return std::any_cast<String>(left) + std::any_cast<String>(right);
            }



            RuntimeError(expr.Operatr(), "Operands must be two numbers or two strings.");

        case TokenType::SLASH:
            checkNumberOperands(expr.Operatr(), left, right);
            if (right.type() == typeid(short)) {
                return std::any_cast<short>(left) / std::any_cast<short>(right);
            }
            else if (right.type() == typeid(int)) {
                return std::any_cast<int>(left) / std::any_cast<int>(right);
            }
            else if (right.type() == typeid(long)) {
                return std::any_cast<long>(left) / std::any_cast<long>(right);
            }
            else if (right.type() == typeid(long long)) {
                return std::any_cast<long long>(left) / std::any_cast<long long>(right);
            }
            else if (right.type() == typeid(float)) {
                return std::any_cast<float>(left) / std::any_cast<float>(right);
            }
            else if (right.type() == typeid(double)) {
                return std::any_cast<double>(left) / std::any_cast<double>(right);
            }
            else if (right.type() == typeid(long double)) {
                return std::any_cast<long double>(left) / std::any_cast<long double>(right);
            }

        case TokenType::STAR:
            checkNumberOperands(expr.Operatr(), left, right);
            if (right.type() == typeid(short)) {
                return std::any_cast<short>(left) * std::any_cast<short>(right);
            }
            else if (right.type() == typeid(int)) {
                return std::any_cast<int>(left) * std::any_cast<int>(right);
            }
            else if (right.type() == typeid(long)) {
                return std::any_cast<long>(left) * std::any_cast<long>(right);
            }
            else if (right.type() == typeid(long long)) {
                return std::any_cast<long long>(left) * std::any_cast<long long>(right);
            }
            else if (right.type() == typeid(float)) {
                return std::any_cast<float>(left) * std::any_cast<float>(right);
            }
            else if (right.type() == typeid(double)) {
                return std::any_cast<double>(left) * std::any_cast<double>(right);
            }
            else if (right.type() == typeid(long double)) {
                return std::any_cast<long double>(left) * std::any_cast<long double>(right);
            }

        case TokenType::BANG_EQUAL: return !isEqual(left, right);
        case TokenType::EQUAL_EQUAL: return isEqual(left, right);
    }

    return nullptr;
}

Object Interpreter::visit(Grouping &expr) {
    return evaluate(expr.Expr());
}

Object Interpreter::visit(Literal &expr) {
    return expr.Value();
}

Object Interpreter::visit(Logical &expr) {
    Object left = evaluate(expr.Left());

    if (expr.Operatr().Type() == TokenType::_from_string("OR")) {
        if (isTruthy(left)) return left;
    } else {
        if (!isTruthy(left)) return left;
    }

    return evaluate(expr.Right());
}

Object Interpreter::visit(Unary &expr) {
    Object right = evaluate(expr.Right());

    switch (expr.Operatr().Type()) {
        case TokenType::BANG:
            return !isTruthy(right);
        case TokenType::MINUS:
            checkNumberOperand(expr.Operatr(), right);

            if (right.type() == typeid(short)) {
                return -std::any_cast<short>(right);
            }
            else if (right.type() == typeid(int)) {
                return -std::any_cast<int>(right);
            }
            else if (right.type() == typeid(long)) {
                return -std::any_cast<long>(right);
            }
            else if (right.type() == typeid(long long)) {
                return -std::any_cast<long long>(right);
            }
            else if (right.type() == typeid(float)) {
                return -std::any_cast<float>(right);
            }
            else if (right.type() == typeid(double)) {
                return -std::any_cast<double>(right);
            }
            else if (right.type() == typeid(long double)) {
                return -std::any_cast<long double>(right);
            }
    }

    return nullptr;
}

Object Interpreter::visit(Variable &expr) {
    return environment.get(expr.Name());
}

Object Interpreter::evaluate(const std::shared_ptr<Expression>& expr) {
    return expr->accept(*this);
}

bool Interpreter::isTruthy(Object object) {
    if (!object.has_value()) {
        return false;
    }

    if (object.type() == typeid(bool)) {
        return std::any_cast<bool>(object);
    }

    return true;
}

bool Interpreter::isEqual(const Object& a, const Object& b) {
    if (a.type() == typeid(short)) {
        return std::any_cast<short>(a) == std::any_cast<short>(b);
    }
    else if (a.type() == typeid(int)) {
        return std::any_cast<int>(a) == std::any_cast<int>(b);
    }
    else if (a.type() == typeid(long)) {
        return std::any_cast<long>(a) == std::any_cast<long>(b);
    }
    else if (a.type() == typeid(long long)) {
        return std::any_cast<long long>(a) == std::any_cast<long long>(b);
    }
    else if (a.type() == typeid(float)) {
        return std::any_cast<float>(a) == std::any_cast<float>(b);
    }
    else if (a.type() == typeid(double)) {
        return std::any_cast<double>(a) == std::any_cast<double>(b);
    }
    else if (a.type() == typeid(long double)) {
        return std::any_cast<long double>(a) == std::any_cast<long double>(b);
    }
    else if (a.type() == typeid(String)) {
        return std::any_cast<String>(a) == std::any_cast<String>(b);
    }
    return true;
}

void Interpreter::checkNumberOperand(Token operatr, const Object& operand) {
    if (operand.type() == typeid(short) || operand.type() == typeid(int) ||
        operand.type() == typeid(long) || operand.type() == typeid(long long) ||
        operand.type() == typeid(float) || operand.type() == typeid(double) ||
        operand.type() == typeid(long double)) {

        return;
    }

    RuntimeError(std::move(operatr), "Operand must be a number.");
}

void Interpreter::checkNumberOperands(Token operatr, const Object& left, const Object& right) {
    if ((left.type() == typeid(short) || left.type() == typeid(int) ||
         left.type() == typeid(long) || left.type() == typeid(long long) ||
         left.type() == typeid(float) || left.type() == typeid(double) ||
         left.type() == typeid(long double)) &&
        (right.type() == typeid(short) || right.type() == typeid(int) ||
         right.type() == typeid(long) || right.type() == typeid(long long) ||
         right.type() == typeid(float) || right.type() == typeid(double) ||
         right.type() == typeid(long double))) {

         return;
    }

    RuntimeError(std::move(operatr), "Operands must be numbers.");
}

Object Interpreter::visit(Block &stmnt) {
    executeBlock(stmnt.Statements(), Environment (environment));
    return nullptr;
}

Object Interpreter::visit(ExpressionStmnt &stmnt) {
    evaluate(stmnt.Expr());
    return nullptr;
}


Object Interpreter::visit(If &stmnt) {
    if (isTruthy(evaluate(stmnt.Condition()))) {
        execute(stmnt.ThenBranch());
    }
    else if (stmnt.ElseBranch() != nullptr) {
        execute(stmnt.ElseBranch());
    }
    return nullptr;
}

Object Interpreter::visit(Print &stmnt) {
    Object value = evaluate(stmnt.Expr());
    std::cout << objectToString(value) << '\n';
    return nullptr;
}

Object Interpreter::visit(Move &stmnt) {
    Object value1 = evaluate(stmnt.Expr1());
    Object value2 = evaluate(stmnt.Expr2());
    String to_shell = "mv " + objectToString(value1) + " " + objectToString(value2);
    system(to_shell.data());

    environment.assign(objectToString(value2), objectToString(value1));

    return nullptr;
}

Object Interpreter::visit(Copy &stmnt) {
    Object value1 = evaluate(stmnt.Expr1());
    Object value2 = evaluate(stmnt.Expr2());
    String to_shell = "cp " + objectToString(value1) + " " + objectToString(value2);
    system(to_shell.data());
    return nullptr;
}

Object Interpreter::visit(Remove &stmnt) {
    Object value = evaluate(stmnt.Expr());

    String to_shell = "rm -rf " + objectToString(value);
    system(to_shell.data());

    environment.deleteVar(objectToString(value));

    return nullptr;
}

Object Interpreter::visit(Find &stmnt) {
    Object value = evaluate(stmnt.Expr());

    String to_shell = "find . -name \"" + objectToString(value) + "\"";
    system(to_shell.data());
    return nullptr;
}

Object Interpreter::visit(FindSame &stmnt) {
    Object value = evaluate(stmnt.Expr());

    String to_shell = "fdupes -r " + objectToString(value);
    system(to_shell.data());
    return nullptr;
}

Object Interpreter::visit(Var &stmnt) {
    Object value = nullptr;
    if (stmnt.Initializer() != nullptr) {
        value = evaluate(stmnt.Initializer());
    }

    if (stmnt.Type() == "File") {
        String to_shell = "touch " + objectToString(value);
        system(to_shell.data());
    }

    environment.define(stmnt.Name().Lexeme(), value);
    return nullptr;
}

Object Interpreter::visit(While &stmnt) {
    while (isTruthy(evaluate(stmnt.Condition()))) {
        execute(stmnt.Body());
    }
    return nullptr;
}

void Interpreter::execute(const std::shared_ptr<Statement>& stmt) {
    stmt->accept(*this);
}

void Interpreter::executeBlock(const Array<std::shared_ptr<Statement>>& statements, Environment environment_arg) {
    Environment previous = this->environment;
    this->environment = std::move(environment_arg);

    for (const std::shared_ptr<Statement>& statement : statements) {
        execute(statement);
    }
}