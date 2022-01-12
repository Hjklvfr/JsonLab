#ifndef JSON_LAB_DECODERPARAMS_H
#define JSON_LAB_DECODERPARAMS_H

class DecoderParams {
    protected:
    bool keepBlankStringValues = false;
    bool trim = true;
    public:
    bool isKeepBlankStringValues() const;
    bool isTrim() const;
};

#endif