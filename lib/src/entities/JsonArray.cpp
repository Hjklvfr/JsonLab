#include "JsonArray.h"

bool JsonArray::isEmpty() const {
    return values.empty();
}

int JsonArray::size() const {
    return values.size();
}

void JsonArray::printTo(std::ostream& oss, int indentation) const {
    oss << "[";
    for(int i = 0; i < size(); i++) {
        values[i]->printTo(oss, indentation);
        if (i != size()-1) oss << ", ";
    }
    oss << "]";
}

JsonValue* JsonArray::get(const int index) {
    return values[index];
}

void JsonArray::add(JsonValue* element) {
    values.push_back(element);
}

void JsonArray::addAll(std::vector<JsonValue*>& elements) {
    for (int i = 0;i < elements.size(); i++) {
        values.push_back(elements[i]);
    }
}
