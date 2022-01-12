#include "JsonNull.h"

JsonNull::JsonNull() {}

void JsonNull::printTo(std::ostream& oss, int indentation) const {
    oss << "null";
}