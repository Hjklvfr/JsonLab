#include "../../_utils/ExceptionsExtensions.h"
#include "../../_utils/StringUtils.h"
#include "JsonStringParser.h"

bool JsonStringParser::isUsed() const {
    return _isUsed;
}

void JsonStringParser::requireNotUsed() const {
    if (isUsed()) {
        throw IllegalStateException("This object cannot be used twice.");
    }
}

Visitor* JsonStringParser::parse() {
    requireNotUsed();

    _isUsed = true;

    processSource();

    return visitor;
}

void JsonStringParser::processSource() {
    while (source->hasNext())
    {
        char ch = source->nextChar();

        processChar(ch);

        if (state == STRING_STOP) {
            visitor->onString(buf.toString());
            source->hasNext();
            return;
        }
    }
}

void JsonStringParser::processChar(char ch) {
    if (ch == '"') state = quote();
    else if (
        ch == '\n' ||
        ch == '\t' ||
        ch == '\r' ||
        ch == '\f' ||
        ch == '\b') 
            throw IllegalStateException("Bad string");
    else state = symbol(ch);
}

StringParserState JsonStringParser::quote() {
    switch (state) {
        case STRING_START: return STRING_START_AFTER;
        case STRING_START_AFTER: return STRING_STOP;
        default: {
            throw IllegalStateException("Unexpected quote");
        }
    }
}

StringParserState JsonStringParser::symbol(char ch) {
    switch (state) {
        case STRING_START_AFTER: {
            append(ch);
            return STRING_START_AFTER;
        }
        default: {
            throw IllegalStateException("Unexpected symbol: " + ch);
        }
    }
}

void JsonStringParser::append(char ch) {
    buf.append(to_string(ch));
}

JsonStringParser::JsonStringParser(Source* source, Visitor* visitor) : source(source), visitor(visitor) {}
