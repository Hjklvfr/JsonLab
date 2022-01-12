#include <ctype.h>
#include "../../rules/Syntax.h"
#include "JsonParser.h"
#include "../../_utils/ExceptionsExtensions.h"
#include "../../_utils/StringUtils.h"
#include "JsonValueParser.h"

bool JsonParser::isUsed() const {
    return _isUsed;
}

void JsonParser::requireNotUsed() const {
    if (isUsed()) {
        throw IllegalStateException("This object cannot be used twice.");
    }
}

Visitor* JsonParser::parse() {
    requireNotUsed();

    _isUsed = true;

    processSource();

    return visitor;
}

void JsonParser::processSource() {

    while (source->hasNext())
    {
        char ch = source->nextChar();

        processChar(ch);

        if (state == PARSER_STOP) {
            return;
        }
    }
    return;
}

void JsonParser::processChar(char ch) {
    if (
            ch == ' ' ||
            ch == '\n' ||
            ch == '\t' ||
            ch == '\r' ||
            ch == '\f' ||
            ch == '\b') state = state;
    else {
        source->prev();
        JsonValueParser(source, visitor).parse();
        source->prev();
    }
}

JsonParser::JsonParser(Source* source, DecoderParams* params, Visitor* visitor) :
        source(source), params(params), visitor(visitor) {}
