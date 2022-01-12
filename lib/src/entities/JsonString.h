#ifndef JSON_LAB_JSONSTRING_H
#define JSON_LAB_JSONSTRING_H

#include <ostream>
#include "JsonValue.h"

class JsonString : public JsonValue {
    private:
    std::string value;

    public:
    JsonString(std::string value);
    const std::string& getValue() const;
    void setValue(const std::string& value);
    void printTo(std::ostream& oss, int indentation) const override;
};

#endif