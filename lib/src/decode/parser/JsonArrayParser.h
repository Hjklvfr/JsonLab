#ifndef JSON_LAB_JSONARRAYPARSER_H
#define JSON_LAB_JSONARRAYPARSER_H

#include "../../source/Source.h"
#include "../../_utils/StringBuilder.h"
#include "Parser.h"

enum ArrayParserState {
    ARRAY_START,
    ARRAY_START_AFTER,
    ARRAY_COMMA_AFTER,
    ARRAY_VALUE_AFTER,
    ARRAY_STOP,
};

class JsonArrayParser : public Parser {
    Source* source;
    Visitor* visitor = nullptr;
    ArrayParserState state = ARRAY_START;
    StringBuilder buf;
    bool _isUsed = false;

    void processSource();
    void processChar(char ch);
    void append(char c);

    ArrayParserState bracket(char ch);
    ArrayParserState comma();
    ArrayParserState symbol(char ch);

    public:
    JsonArrayParser(Source* source, Visitor* visitor);
    bool isUsed() const override;
    void requireNotUsed() const override;
    Visitor* parse() override;
};

#endif