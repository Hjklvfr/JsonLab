#ifndef JSON_LAB_JSONPARSER_H
#define JSON_LAB_JSONPARSER_H

#include "../../source/Source.h"
#include "../DecoderParams.h"
#include "../../_utils/StringBuilder.h"
#include "../../entities/JsonValue.h"
#include "Parser.h"
#include "ParserState.h"

class JsonParser : public Parser {
    private:
    Source* source;
    DecoderParams* params;
    Visitor* visitor = nullptr;
    ParserState state = PARSER_STOP;
    StringBuilder buf;

    bool _isUsed = false;
    
    public:
    JsonParser(Source* source, DecoderParams* params, Visitor* visitor);

    bool isUsed() const override;
    void requireNotUsed() const override;

    Visitor* parse() override;

    private:
    void processSource();
    void processChar(char ch);
};

#endif