#ifndef JSON_LAB_PARSERFACTORY_H
#define JSON_LAB_PARSERFACTORY_H

#include "../../source/Source.h"
#include "Visitor.h"
#include "../DecoderParams.h"
#include "JsonParser.h"

class JsonParserFactory {
    private:
    DecoderParams* decoderParams;

    public:
    explicit JsonParserFactory(DecoderParams* decoderParams);
    virtual Parser* get(Source* source, Visitor* visitor);
    virtual ~JsonParserFactory();
};

#endif