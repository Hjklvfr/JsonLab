#ifndef JSON_LAB_ENCODERPARAMS_H
#define JSON_LAB_ENCODERPARAMS_H

class EncoderParams {
    protected:
    bool beautify = true;
    public:
    bool isBeautify() const;
};

#endif