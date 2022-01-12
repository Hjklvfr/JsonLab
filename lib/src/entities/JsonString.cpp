#include "../_utils/StringUtils.h"
#include "../rules/Syntax.h"
#include "JsonString.h"

JsonString::JsonString(std::string value) : value(std::move(value)) {}

const std::string& JsonString::getValue() const {
    return value;
}

void JsonString::setValue(const std::string& value) {
    JsonString::value = value;
}

void JsonString::printTo(std::ostream& os, int indentation) const {
    std::string indentations = repeat(INDENTATION, indentation);
    os << indentations << "\"" << value << "\"";
}
