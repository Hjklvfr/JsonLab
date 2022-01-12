#ifndef JSON_LAB_JSONWRITERFACTORY_H
#define JSON_LAB_JSONWRITERFACTORY_H

#include "../EncoderParams.h"
#include "../../sink/Sink.h"
#include "Writer.h"

class JsonWriterFactory {
    private:
    EncoderParams* params;

    public:
    explicit JsonWriterFactory(EncoderParams* params);
    Writer* get(Sink* sink);
    virtual ~JsonWriterFactory();
};

#endif