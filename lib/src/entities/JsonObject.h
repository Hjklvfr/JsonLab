#ifndef JSON_LAB_JSONOBJECT_H
#define JSON_LAB_JSONOBJECT_H

#include "JsonValue.h"
#include "JsonMember.h"
#include <functional>
#include <vector>

class JsonObject : public JsonValue {
    private:
    std::vector<JsonMember*> members;

    public:
    bool isEmpty() const;
    int size() const;
    void printTo(std::ostream& oss, int indentation) const override;
    void forEachMember(const std::function<void(int, JsonMember*)>& consumer);
    void addMember(JsonMember* member);
};

#endif