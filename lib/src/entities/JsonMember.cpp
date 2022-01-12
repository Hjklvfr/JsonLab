#include "JsonNull.h"
#include "JsonMember.h"

JsonMember::JsonMember(JsonString* name, JsonValue* value) : name(name), value(value) {}

JsonMember::JsonMember(JsonString* name) : JsonMember(name, nullptr) {}

JsonMember::JsonMember() : JsonMember(nullptr, nullptr) {}

void JsonMember::printTo(std::ostream& oss, int indentation) const {
    name->printTo(oss, indentation);
    oss << ": ";
    value->printTo(oss, indentation); 
}

std::string JsonMember::getName() const {
    return name->getValue();
}

JsonValue* JsonMember::getValue() const {
    return value;
}

void JsonMember::setName(JsonString* name) {
    JsonMember::name = name;
}

void JsonMember::setValue(JsonValue* value) {
    JsonMember::value = value;
}
