#include "JsonBool.h"

JsonBool::JsonBool(bool value) : value(value) {}

const bool JsonBool::getValue() const {
    return value;
}

void JsonBool::setValue(bool value) {
    JsonBool::value = value;
}

void JsonBool::printTo(std::ostream& oss, int indentation) const {
    if (value) {
        oss << "true";
    } else {
        oss << "false";
    }
}
