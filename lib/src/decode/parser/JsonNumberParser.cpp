#include <ctype.h>
#include "../../_utils/ExceptionsExtensions.h"
#include "../../_utils/StringUtils.h"
#include "JsonNumberParser.h"

bool JsonNumberParser::isUsed() const {
    return _isUsed;
}

void JsonNumberParser::requireNotUsed() const {
    if (isUsed()) {
        throw IllegalStateException("This object cannot be used twice.");
    }
}

Visitor* JsonNumberParser::parse() {
    requireNotUsed();

    _isUsed = true;

    processSource();

    return visitor;
}

void JsonNumberParser::processSource() {
    while (source->hasNext())
    {
        char ch = source->nextChar();

        processChar(ch);

        if (state == NUMBER_STOP) {
            visitor->onNumber(buf.toString());
            return;
        }
    }
    visitor->onNumber(buf.toString());
}

void JsonNumberParser::processChar(char ch) {
    if(ch == '-' || ch == '+') state = sign(ch);
    else if(isdigit(ch)) state = digit(ch - '0');
    else if(ch == '.') state = point();
    else if(ch == 'e' || ch == 'E') state = exponent(ch);
    else if(
        state == NUMBER_FIRST_DIGIT_ZERO || 
        state == NUMBER_FIRST_DIGIT_NOT_ZERO ||
        state == NUMBER_FIRST_DIGIT_NOT_ZERO_AFTER ||
        state == NUMBER_FRACTION_POINT_AFTER ||
        state == NUMBER_EXPONENT_SIGN_AFTER
        ) state = NUMBER_STOP;
    else {
        throw IllegalStateException("Unexpected symbol: " + ch);
    }
}

NumberParserState JsonNumberParser::exponent(char exponent) {
    switch (state) {
        case NUMBER_FRACTION_POINT_AFTER: {
            append(exponent);
            return NUMBER_EXPONENT_SYMBOL;
        }
        default: {
            throw IllegalStateException("Unexpected exponent symbol");
        }
    }
}

NumberParserState JsonNumberParser::point() {
    switch (state) {
        case NUMBER_FIRST_DIGIT_NOT_ZERO:
        case NUMBER_FIRST_DIGIT_NOT_ZERO_AFTER:
        case NUMBER_FIRST_DIGIT_ZERO: {
            append('.');
            return NUMBER_FRACTION_POINT;
        }
        default: {
            throw IllegalStateException("Unexpected fraction point");
        }
    }
}

NumberParserState JsonNumberParser::digit(int digit) {
    switch (state) {
        case NUMBER_START: {
            if (digit == 0) {
                append('0');
                return NUMBER_FIRST_DIGIT_ZERO;
            } else {
                append('0' + digit);
                return NUMBER_FIRST_DIGIT_NOT_ZERO;
            }
        }
        case NUMBER_FIRST_DIGIT_NOT_ZERO:
        case NUMBER_FIRST_DIGIT_NOT_ZERO_AFTER: {
            append('0' + digit);
            return NUMBER_FIRST_DIGIT_NOT_ZERO_AFTER;
        }
        case NUMBER_FRACTION_POINT:
        case NUMBER_FRACTION_POINT_AFTER: {
            append('0' + digit);
            return NUMBER_FRACTION_POINT_AFTER;
        }
        case NUMBER_EXPONENT_SIGN:
        case NUMBER_EXPONENT_SIGN_AFTER: {
            append('0' + digit);
            return NUMBER_EXPONENT_SIGN_AFTER;
        }
        default: {
            throw IllegalStateException("Unexpected digit");
        }
    }
}

NumberParserState JsonNumberParser::sign(char sign) {
    switch (state) {
    case NUMBER_START: {
        append(sign);
        return NUMBER_AFTER_SIGN;
    }
    case NUMBER_EXPONENT_SYMBOL: {
        append(sign);
        return NUMBER_EXPONENT_SIGN;
    }
    default:
        throw IllegalStateException("Unexpected sign");
    }
}

void JsonNumberParser::append(char ch) {
    buf.append(to_string(ch));
}

JsonNumberParser::JsonNumberParser(Source* source, Visitor* visitor) : source(source), visitor(visitor) {}
