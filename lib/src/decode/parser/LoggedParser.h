#ifndef JSON_LAB_LOGGEDPARSER_H
#define JSON_LAB_LOGGEDPARSER_H

#include <plog/Severity.h>
#include "JsonParser.h"

class LoggedParser : public Parser {
    private:
    Parser* parser;
    plog::Severity logLevel;

    public:
    LoggedParser(Parser* parser, plog::Severity logLevel);

    bool isUsed() const override;
    void requireNotUsed() const override;

    Visitor* parse() override;
};

#endif