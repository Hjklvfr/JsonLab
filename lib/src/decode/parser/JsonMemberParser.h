#ifndef JSON_LAB_JSONMEMBERPARSER_H
#define JSON_LAB_JSONMEMBERPARSER_H

#include "../../source/Source.h"
#include "../../_utils/StringBuilder.h"
#include "Parser.h"

enum MemberParserState {
    MEMBER_START,
    MEMBER_NAME_AFTER,
    MEMBER_COLON_AFTER,
    MEMBER_STOP,
};

class JsonMemberParser : public Parser {
    Source* source;
    Visitor* visitor = nullptr;
    MemberParserState state = MemberParserState::MEMBER_START;
    StringBuilder buf;
    bool _isUsed = false;

    void processSource();
    void processChar(char ch);
    void append(char c);

    MemberParserState quote();
    MemberParserState colon();
    MemberParserState symbol(char ch);

    public:
    JsonMemberParser(Source* source, Visitor* visitor);
    bool isUsed() const override;
    void requireNotUsed() const override;
    Visitor* parse() override;
};

#endif