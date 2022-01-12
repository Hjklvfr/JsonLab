#ifndef JSON_LAB_JSONOBJECTPARSER_H
#define JSON_LAB_JSONOBJECTPARSER_H

#include "../../source/Source.h"
#include "../../_utils/StringBuilder.h"
#include "Parser.h"

enum ObjectParserState {
    OBJECT_START,
    OBJECT_START_AFTER,
    OBJECT_MEMBER_AFTER,
    OBJECT_COMMA_AFTER,
    OBJECT_STOP,
};

class JsonObjectParser: public Parser {
    Source* source;
    Visitor* visitor = nullptr;
    ObjectParserState state = ObjectParserState::OBJECT_START;
    StringBuilder buf;
    bool _isUsed = false;

    void processSource();
    void processChar(char ch);
    void append(char c);

    ObjectParserState bracket(char ch);
    ObjectParserState comma();
    ObjectParserState quote();

    public:
    JsonObjectParser(Source* source, Visitor* visitor);
    bool isUsed() const override;
    void requireNotUsed() const override;
    Visitor* parse() override;
};

#endif