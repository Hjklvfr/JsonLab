#include "../../_utils/ExceptionsExtensions.h"
#include "../../_utils/StringUtils.h"
#include "JsonValueParser.h"
#include "JsonArrayParser.h"


bool JsonArrayParser::isUsed() const {
    return _isUsed;
}

void JsonArrayParser::requireNotUsed() const {
    if (isUsed()) {
        throw IllegalStateException("This object cannot be used twice.");
    }
}

Visitor* JsonArrayParser::parse() {
    requireNotUsed();

    _isUsed = true;

    processSource();

    return visitor;
}

void JsonArrayParser::processSource() {
    while (source->hasNext())
    {
        char ch = source->nextChar();
        
        if (state == ARRAY_START) {
            visitor->onArrayStart();
        }
        processChar(ch);

        if (state == ARRAY_STOP) {
            visitor->onArrayEnd();
            return;
        }
    }
}

void JsonArrayParser::processChar(char ch) {
    if (ch == '[' || ch == ']') state = bracket(ch);
    else if (ch == ',') state = comma();
    else if ((
            ch == ' ' ||
            ch == '\n' ||
            ch == '\t' ||
            ch == '\r' ||
            ch == '\f' ||
            ch == '\b') && state == ARRAY_COMMA_AFTER) state = state;
    else state = symbol(ch);
}

ArrayParserState JsonArrayParser::bracket(char ch) {
    switch (state) {
        case ARRAY_START: {
            if (ch == '[') return ARRAY_START_AFTER;
            else throw IllegalStateException("Unexpected symbol: " + ch);
        }
        case ARRAY_START_AFTER: {
            if (ch == ']') return ARRAY_STOP;
            else if (ch == '[') {
                source->prev();
                JsonValueParser(source, visitor).parse();
                source->prev();
                return ARRAY_VALUE_AFTER;
            } else {
                throw IllegalStateException("Unexpected array bracket");
            }
        }
        case ARRAY_VALUE_AFTER: {
            if (ch == ']') return ARRAY_STOP;
            else throw IllegalStateException("Unexpected symbol: " + ch);
        }
        case ARRAY_COMMA_AFTER: {
            if (ch == '[') {
                source->prev();
                JsonValueParser(source, visitor).parse();
                source->prev();
                return ARRAY_VALUE_AFTER;
            }
            else throw IllegalStateException("Unexpected symbol: " + ch);
        }
        default: {
            throw IllegalStateException("Unexpected array bracket");
        }
    }
}

ArrayParserState JsonArrayParser::comma() {
    switch (state) {
        case ARRAY_VALUE_AFTER: return ARRAY_COMMA_AFTER;
        default: {
            throw IllegalStateException("Unexpected comma");
        }
    }
}

ArrayParserState JsonArrayParser::symbol(char ch) {
    switch (state) {
        case ARRAY_COMMA_AFTER:
        case ARRAY_START_AFTER: {
            source->prev();
            JsonValueParser(source, visitor).parse();
            source->prev();
            return ARRAY_VALUE_AFTER;
        }
        default:
            throw IllegalStateException("Unexpected symbol: " + ch);
    }
}

JsonArrayParser::JsonArrayParser(Source* source, Visitor* visitor) : source(source), visitor(visitor) {}
