#ifndef JSON_LAB_JSONNULL_H
#define JSON_LAB_JSONNULL_H

#include <ostream>
#include "JsonValue.h"

class JsonNull : public JsonValue {
    public:
    JsonNull();
    void printTo(std::ostream& oss, int indentation) const override;
};

#endif