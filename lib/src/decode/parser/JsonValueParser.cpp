#include "ctype.h"
#include "../../_utils/ExceptionsExtensions.h"
#include "../../_utils/StringUtils.h"
#include "JsonNumberParser.h"
#include "JsonStringParser.h"
#include "JsonArrayParser.h"
#include "JsonObjectParser.h"
#include "JsonValueParser.h"

bool JsonValueParser::isUsed() const {
    return _isUsed;
}

void JsonValueParser::requireNotUsed() const {
    if (isUsed()) {
        throw IllegalStateException("This object cannot be used twice.");
    }
}

Visitor* JsonValueParser::parse() {
    requireNotUsed();

    _isUsed = true;

    processSource();

    return visitor;
}

void JsonValueParser::processSource() {
    while (source->hasNext())
    {
        char ch = source->nextChar();

        processChar(ch);

        if (state == VALUE_STOP) return;
        else if (state == VALUE_STOP_TRUE) {
            visitor->onBool(true);
            source->hasNext();
            return;
        }
        else if (state == VALUE_STOP_FALSE) {
            visitor->onBool(false);
            source->hasNext();
            return;
        }
        else if (state == VALUE_STOP_NULL) {
            visitor->onNull();
            source->hasNext();
            return;
        }
    }
}

void JsonValueParser::processChar(char ch) {
    switch (state) {
        case VALUE_START: {
            if (ch == 't') {
                source->prev();
                state = VALUE_READ_TRUE;
            }
            else if (ch == 'f') {
                source->prev();
                state = VALUE_READ_FALSE;
            }
            else if (ch == 'n') {
                source->prev();
                state = VALUE_READ_NULL;
            }
            else if (
                ch == ' ' ||
                ch == '\n' ||
                ch == '\t' ||
                ch == '\r' ||
                ch == '\f' ||
                ch == '\b') state = VALUE_START;
            else if (ch == '{') {
                source->prev();
                JsonObjectParser(source, visitor).parse();
                source->prev();
                state = VALUE_READ_AFTER;
            }
            else if (ch == '[') {
                source->prev();
                JsonArrayParser(source, visitor).parse();
                source->prev();
                state = VALUE_READ_AFTER;
            }
            else if (isdigit(ch) || ch == '-') {
                source->prev();
                JsonNumberParser(source, visitor).parse();
                source->prev();
                state = VALUE_READ_AFTER;
            } else if (ch == '"') {
                source->prev();
                JsonStringParser(source, visitor).parse();
                state = VALUE_STOP;
            }
            else throw IllegalStateException("Unexpected symbol: " + ch);
            return;
        }
        case VALUE_READ_TRUE: {
            auto str = buf.toString();
            if (std::string("true").rfind(str + ch) == 0) {
                append(ch);
                state = VALUE_READ_TRUE;
            } else
                throw IllegalStateException("Unexpected symbol: " + ch);
            if (std::string("true") == buf.toString())
                state = VALUE_STOP_TRUE;
            return;
        }
        case VALUE_READ_FALSE: {
            auto str = buf.toString();
            if (std::string("false").rfind(str + ch) == 0) {
                append(ch);
                state = VALUE_READ_FALSE;
            } else
                throw IllegalStateException("Unexpected symbol: " + ch);
            if (std::string("false") == buf.toString()) 
                state = VALUE_STOP_FALSE;
            return;
        }
        case VALUE_READ_NULL: {
            auto str = buf.toString();
            if (std::string("null").rfind(str + ch) == 0) {
                append(ch);
                state = VALUE_READ_NULL;
            } else 
                throw IllegalStateException("Unexpected symbol: " + ch);
            if (std::string("null") == buf.toString()) 
                state = VALUE_STOP_NULL;
            return;
        }
        case VALUE_READ_AFTER: {
            if (
                ch == ' ' ||
                ch == '\n' ||
                ch == '\t' ||
                ch == '\r' ||
                ch == '\f' ||
                ch == '\b') state = VALUE_READ_AFTER;
            else state = VALUE_STOP;
            return;
        }
    }
}

void JsonValueParser::append(char ch) {
    buf.append(to_string(ch));
}

JsonValueParser::JsonValueParser(Source* source, Visitor* visitor) : source(source), visitor(visitor) {}
