#include "JsonWriterFactory.h"

JsonWriterFactory::JsonWriterFactory(EncoderParams* params) : params(params) {
    if (this->params == nullptr) {
        throw std::invalid_argument("Params cannot be null");
    }
}

Writer* JsonWriterFactory::get(Sink* sink) {
    if (sink == nullptr) {
        throw std::invalid_argument("Source cannot be null");
    }
    return new Writer(sink, params);
}

JsonWriterFactory::~JsonWriterFactory() {
    delete params;
}
