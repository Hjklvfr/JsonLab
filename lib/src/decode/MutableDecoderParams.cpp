#include "../../include/json_lab/MutableDecoderParams.h"

void MutableDecoderParams::setKeepBlankStringValues(bool keepBlankStringValues) {
    MutableDecoderParams::keepBlankStringValues = keepBlankStringValues;
}

void MutableDecoderParams::setTrim(bool trim) {
    MutableDecoderParams::trim = trim;
}