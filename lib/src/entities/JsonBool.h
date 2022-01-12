#ifndef JSON_LAB_JSONBOOL_H
#define JSON_LAB_JSONBOOL_H

#include <ostream>
#include "JsonValue.h"

class JsonBool : public JsonValue {
    private:
    bool value;

    public:
    JsonBool(bool value);
    const bool getValue() const;
    void setValue(bool value);
    void printTo(std::ostream& oss, int indentation) const override;
};

#endif