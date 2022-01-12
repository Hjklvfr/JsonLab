#include "JsonObject.h"

#include <iostream>

bool JsonObject::isEmpty() const {
    return members.empty();
}

int JsonObject::size() const {
    return members.size();
}

void JsonObject::printTo(std::ostream& oss, int indentation) const {
    oss << "{";
    for(int i = 0; i < size(); i++) {
        members[i]->printTo(oss, indentation);
        if (i != size()-1) oss << ", ";
    }
    oss << "}";
}

void JsonObject::forEachMember(const std::function<void(int, JsonMember*)>& consumer) {
    int limit = size();
    for (int i = 0; i < limit; i++) {
        consumer(i, members[i]);
    }
}

void JsonObject::addMember(JsonMember* member) {
    members.push_back(member);
}
