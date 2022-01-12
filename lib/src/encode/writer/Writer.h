#ifndef JSON_LAB_WRITER_H
#define JSON_LAB_WRITER_H

#include "../../entities/JsonString.h"
#include "../../sink/Sink.h"
#include "../EncoderParams.h"

class Writer {
    private:
    Sink* sink;
    EncoderParams* params;
    int indentation = 0;
    bool _isUsed = false;

    public:
    Writer(Sink* sink, EncoderParams* params);
    bool isUsed() const;
    void requireNotUsed() const;
    Sink* write(JsonString* element);

    private:
    void writeString(JsonString* string);
    void appendIndentation();
};

#endif