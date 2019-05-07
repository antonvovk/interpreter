#include "Utils.h"

String objectToString(const Object& any) {
    if (any.type() == typeid(short)) {
        return std::to_string(std::any_cast<short>(any));
    }
    else if (any.type() == typeid(int)) {
        return std::to_string(std::any_cast<int>(any));
    }
    else if (any.type() == typeid(long)) {
        return std::to_string(std::any_cast<long>(any));
    }
    else if (any.type() == typeid(long long)) {
        return std::to_string(std::any_cast<long long>(any));
    }
    else if (any.type() == typeid(float)) {
        return std::to_string(std::any_cast<float>(any));
    }
    else if (any.type() == typeid(double)) {
        return std::to_string(std::any_cast<double>(any));
    }
    else if (any.type() == typeid(long double)) {
        return std::to_string(std::any_cast<long double>(any));
    }
    else if (any.type() == typeid(const char*)) {
        return std::string(std::any_cast<const char*>(any));
    }
    else if (any.type() == typeid(char)) {
        return std::string(1, std::any_cast<char>(any));
    }
    else if (any.type() == typeid(bool)) {
        return std::to_string(std::any_cast<bool>(any));
    }
    else {
        return std::any_cast<String>(any);
    }
}
