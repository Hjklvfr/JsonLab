#include "JsonNumber.h"

JsonNumber::JsonNumber(std::string value) : value(value) {}

const std::string JsonNumber::getValue() const {
    return value;
}

void JsonNumber::setValue(std::string value) {
    JsonNumber::value = value;
}

void JsonNumber::printTo(std::ostream& oss, int indentation) const {
    oss << value;
}