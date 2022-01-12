#ifndef JSON_LAB_JSONNUMBERPARSER_H
#define JSON_LAB_JSONNUMBERPARSER_H

#include "../../source/Source.h"
#include "../../_utils/StringBuilder.h"
#include "Parser.h"

enum NumberParserState {
    NUMBER_START,
    NUMBER_AFTER_SIGN, // may not contain sign
    NUMBER_FIRST_DIGIT_ZERO, // fraction or exponent or zero
    NUMBER_FIRST_DIGIT_NOT_ZERO,
    NUMBER_FIRST_DIGIT_NOT_ZERO_AFTER, // add another digits
    NUMBER_FRACTION_POINT,
    NUMBER_FRACTION_POINT_AFTER, // must contain >=1 digits after point
    NUMBER_EXPONENT_SYMBOL, // E or e
    NUMBER_EXPONENT_SIGN, // may not contain sign
    NUMBER_EXPONENT_SIGN_AFTER, // must contain >=1 digits after sign
    NUMBER_STOP,
};

class JsonNumberParser : public Parser {
    private:
    Source* source;
    Visitor* visitor = nullptr;
    NumberParserState state = NUMBER_START;
    StringBuilder buf;
    bool _isUsed = false;

    void processSource();
    void processChar(char ch);
    void append(char c);

    NumberParserState sign(char sign);
    NumberParserState digit(int digit);
    NumberParserState point();
    NumberParserState exponent(char exponent);

    public:
    JsonNumberParser(Source* source, Visitor* visitor);
    bool isUsed() const override;
    void requireNotUsed() const override;
    Visitor* parse() override;
};

#endif
