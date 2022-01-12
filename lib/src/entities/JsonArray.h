#ifndef JSON_LAB_JSONARRAY_H
#define JSON_LAB_JSONARRAY_H

#include <functional>
#include <vector>
#include "JsonValue.h"

class JsonArray : public JsonValue {
    private:
    std::vector<JsonValue*> values;

    public:
    bool isEmpty() const;
    int size() const;
    void printTo(std::ostream& oss, int indentation) const override;

    JsonValue* get(const int index);
    void add(JsonValue* element);
    void addAll(std::vector<JsonValue*>& elements);
};

#endif
