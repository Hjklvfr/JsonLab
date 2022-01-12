#include "../../_utils/ExceptionsExtensions.h"
#include "../../_utils/StringUtils.h"
#include "JsonMemberParser.h"
#include "JsonObjectParser.h"


bool JsonObjectParser::isUsed() const {
    return _isUsed;
}

void JsonObjectParser::requireNotUsed() const {
    if (isUsed()) {
        throw IllegalStateException("This object cannot be used twice.");
    }
}

Visitor* JsonObjectParser::parse() {
    requireNotUsed();

    _isUsed = true;

    processSource();

    return visitor;
}

void JsonObjectParser::processSource() {
    while (source->hasNext())
    {
        char ch = source->nextChar();

        if (state == OBJECT_START) {
            visitor->onObjectStart();
        }

        processChar(ch);

        if (state == OBJECT_STOP) {
            visitor->onObjectEnd();
            source->hasNext();
            return;
        }
    }
}

void JsonObjectParser::processChar(char ch) {
    if (ch == '{' || ch == '}') state = bracket(ch);
    else if (ch == ',') state = comma();
    else if (ch == '"') state = quote();
    else if ((
            ch == ' ' ||
            ch == '\n' ||
            ch == '\t' ||
            ch == '\r' ||
            ch == '\f' ||
            ch == '\b') && state == OBJECT_COMMA_AFTER) state = state;
    else throw IllegalStateException("Unexpected symbol: " + ch);
}

ObjectParserState JsonObjectParser::bracket(char ch) {
    switch (state) {
        case OBJECT_START: {
            if (ch == '{') return OBJECT_START_AFTER;
            else throw IllegalStateException("Unexpected symbol: " + ch);
        }
        case OBJECT_MEMBER_AFTER:
        case OBJECT_START_AFTER: {
            if (ch == '}') return OBJECT_STOP;
            else throw IllegalStateException("Unexpected symbol: " + ch);
        }
        default: {
            throw IllegalStateException("Unexpected bracket");
        }
    }
}

ObjectParserState JsonObjectParser::comma() {
    switch (state) {
        case OBJECT_MEMBER_AFTER: return OBJECT_COMMA_AFTER;
        default: {
            throw IllegalStateException("Unexpected comma");
        }
    }
}

ObjectParserState JsonObjectParser::quote() {
    switch (state) {
        case OBJECT_COMMA_AFTER:
        case OBJECT_START_AFTER: {
            source->prev();
            JsonMemberParser(source, visitor).parse();
            return OBJECT_MEMBER_AFTER;
        }
        default:
            throw IllegalStateException("Unexpected quote1");
    }
}

JsonObjectParser::JsonObjectParser(Source* source, Visitor* visitor) : source(source), visitor(visitor) {}
