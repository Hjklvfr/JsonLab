#ifndef JSON_LAB_JSONMEMBER_H
#define JSON_LAB_JSONMEMBER_H

#include <string>
#include "JsonString.h"
#include "JsonValue.h"

class JsonMember : public JsonValue {
    private: 
    JsonString* name;
    JsonValue* value;
    
    public:
    JsonMember(JsonString* name, JsonValue* value);
    JsonMember(JsonString* name);
    JsonMember();
    void printTo(std::ostream& oss, int indentation) const override;
    std::string getName() const;
    JsonValue* getValue() const;
    void setName(JsonString* name);
    void setValue(JsonValue* value);
};

#endif