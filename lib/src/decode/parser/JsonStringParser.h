#ifndef JSON_LAB_JSONSTRINGPARSER_H
#define JSON_LAB_JSONSTRINGPARSER_H

#include "../../source/Source.h"
#include "../../_utils/StringBuilder.h"
#include "Parser.h"

enum StringParserState{
    STRING_START,
    STRING_START_AFTER,
    STRING_STOP,
};

class JsonStringParser : public Parser {
    Source* source;
    Visitor* visitor = nullptr;
    StringParserState state = StringParserState::STRING_START;
    StringBuilder buf;
    bool _isUsed = false;

    void processSource();
    void processChar(char ch);
    void append(char c);

    StringParserState quote();
    StringParserState symbol(char ch);

    public:
    JsonStringParser(Source* source, Visitor* visitor);
    bool isUsed() const override;
    void requireNotUsed() const override;
    Visitor* parse() override;
};

#endif