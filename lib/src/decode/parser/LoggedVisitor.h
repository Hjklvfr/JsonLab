#ifndef JSON_LAB_LOGGEDVISITOR_H
#define JSON_LAB_LOGGEDVISITOR_H

#include <plog/Severity.h>
#include "Visitor.h"

class LoggedVisitor : public Visitor {
    private:
    Visitor& visitor;
    plog::Severity logLevel;

    public:
    LoggedVisitor(Visitor& visitor, plog::Severity log);
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
};

#endif