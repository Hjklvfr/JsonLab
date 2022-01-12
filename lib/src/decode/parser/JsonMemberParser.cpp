#include "../../_utils/ExceptionsExtensions.h"
#include "../../_utils/StringUtils.h"
#include "JsonValueParser.h"
#include "JsonStringParser.h"
#include "JsonMemberParser.h"


bool JsonMemberParser::isUsed() const {
    return _isUsed;
}

void JsonMemberParser::requireNotUsed() const {
    if (isUsed()) {
        throw IllegalStateException("This object cannot be used twice.");
    }
}

Visitor* JsonMemberParser::parse() {
    requireNotUsed();

    _isUsed = true;

    processSource();

    return visitor;
}

void JsonMemberParser::processSource() {
    while (source->hasNext())
    {
        char ch = source->nextChar();

        if (state == MEMBER_START) {
            visitor->onObjectMemberStart();
        }

        processChar(ch);

        if (state == MEMBER_STOP) {
            visitor->onObjectMemberEnd();
            return;
        }
    }
}

void JsonMemberParser::processChar(char ch) {
    if (ch == '"') state = quote();
    else if (ch == ':') state = colon();
    else if ((
            ch == ' ' ||
            ch == '\n' ||
            ch == '\t' ||
            ch == '\r' ||
            ch == '\f' ||
            ch == '\b') && state == MEMBER_START || state == MEMBER_NAME_AFTER) state = state;
    else state = symbol(ch);
}

MemberParserState JsonMemberParser::quote() {
    switch (state) {
        case MEMBER_START: {
            source->prev();
            JsonStringParser(source, visitor).parse();
            source->prev();
            return MEMBER_NAME_AFTER;
        }
        case MEMBER_COLON_AFTER: {
            source->prev();
            JsonStringParser(source, visitor).parse();
            source->prev();
            return MEMBER_STOP;
        }
        default: {
            throw IllegalStateException("Unexpected quote");
        }
    }
}

MemberParserState JsonMemberParser::colon() {
    switch (state) {
        case MEMBER_NAME_AFTER: {
            return MEMBER_COLON_AFTER;
        }
        default: {
            throw IllegalStateException("Unexpected colon");
        }
    }
}

MemberParserState JsonMemberParser::symbol(char ch) {
    switch (state) {
        case MEMBER_COLON_AFTER: {
            source->prev();
            JsonValueParser(source, visitor).parse();
            source->prev();
            return MEMBER_STOP;
        }
        default: {
            throw IllegalStateException("Unexpected fraction point");
        }
    }
}

JsonMemberParser::JsonMemberParser(Source* source, Visitor* visitor) : source(source), visitor(visitor) {}
