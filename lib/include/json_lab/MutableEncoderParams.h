#ifndef JSON_LAB_MUTABLEENCODERPARAMS_H
#define JSON_LAB_MUTABLEENCODERPARAMS_H

#include "../../src/encode/EncoderParams.h"

class MutableEncoderParams : public EncoderParams {
    public:
    void setBeautify(bool beautify);    
};

#endif