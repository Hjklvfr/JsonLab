#ifndef JSON_LAB_JSONVALUE_H
#define JSON_LAB_JSONVALUE_H

#include "../_utils/ClassExtensions.h"
#include "JsonElement.h"
#include <ostream>

class JsonValue : public JsonElement {
    public:
    virtual void printTo(std::ostream& oss, int indentation) const = 0;
};

#endif