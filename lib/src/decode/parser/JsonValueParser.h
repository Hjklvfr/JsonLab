#ifndef JSON_LAB_JSONVALUEPARSER_H
#define JSON_LAB_JSONVALUEPARSER_H

#include "../../source/Source.h"
#include "../../_utils/StringBuilder.h"
#include "Parser.h"

enum ValueParserState {
    VALUE_START,
    VALUE_READ_TRUE,
    VALUE_READ_FALSE,
    VALUE_READ_NULL,
    VALUE_READ_AFTER,
    VALUE_STOP,
    VALUE_STOP_TRUE,
    VALUE_STOP_FALSE,
    VALUE_STOP_NULL,
};

class JsonValueParser : public Parser {
    Source* source;
    Visitor* visitor = nullptr;
    ValueParserState state = ValueParserState::VALUE_START;
    StringBuilder buf;
    bool _isUsed = false;

    void processSource();
    void processChar(char ch);
    void append(char c);

    ValueParserState whitespace();
    ValueParserState readTrue(char ch);
    ValueParserState readFasle(char ch);
    ValueParserState readNull(char ch);
    ValueParserState symbol(char ch);

    public:
    JsonValueParser(Source* source, Visitor* visitor);
    bool isUsed() const override;
    void requireNotUsed() const override;
    Visitor* parse() override;
};

#endif