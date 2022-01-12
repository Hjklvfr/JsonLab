#ifndef JSON_LAB_JSONNUMBER_H
#define JSON_LAB_JSONNUMBER_H

#include <ostream>
#include "JsonValue.h"

class JsonNumber : public JsonValue {
    private:
    std::string value;

    public:
    JsonNumber(std::string value);
    const std::string getValue() const;
    void setValue(std::string value);
    void printTo(std::ostream& oss, int indentation) const override;
};

#endif