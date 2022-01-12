#include "JsonParserFactory.h"

JsonParserFactory::JsonParserFactory(DecoderParams* params) : decoderParams(decoderParams) {
    if (this->decoderParams == nullptr) {
        throw std::invalid_argument("Decoder Params cannot be null");
    }
}

Parser* JsonParserFactory::get(Source* source, Visitor* visitor) {
    if (source == nullptr) {
        throw std::invalid_argument("Source cannot be null");
    }

    Parser* parser = new JsonParser(source, decoderParams, visitor);
    return parser;
}

JsonParserFactory::~JsonParserFactory() {
    delete decoderParams;
}