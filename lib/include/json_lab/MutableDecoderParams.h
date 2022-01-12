#ifndef JSON_LAB_MUTABLEDECODERPARAMS_H
#define JSON_LAB_MUTABLEDECODERPARAMS_H

#include "../../src/decode/DecoderParams.h"

class MutableDecoderParams : public DecoderParams {
    public:
    void setKeepBlankStringValues(bool keepBlankStringValues);
    void setTrim(bool trim);
};

#endif