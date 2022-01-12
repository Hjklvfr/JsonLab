#ifndef JSON_LAB_ELEMENTBUILDER_H
#define JSON_LAB_ELEMENTBUILDER_H

#include <vector>
#include "../../entities/JsonValue.h"
#include "../../entities/JsonObject.h"
#include "Visitor.h"

// LAB 2

class ElementBuilder : public Visitor {
    private:
    JsonValue* root = nullptr;
    std::vector<JsonValue*> branch;
    JsonValue* getCurrent() const;
    JsonValue* getCurrentsParent() const;
    
    public:
    void onNumber(std::string value) override;
    void onString(std::string value) override;
    void onBool(bool value) override;
    void onNull() override;
    void onObjectStart() override;
    void onObjectMemberStart() override;
    void onObjectMemberEnd() override;
    void onObjectEnd() override;
    void onArrayStart() override;
    void onArrayEnd() override;

    JsonValue* getRoot() const;
};

#endif