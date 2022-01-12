#include "../../rules/Syntax.h"
#include "Writer.h"

Writer::Writer(Sink* sink, EncoderParams* params) : sink(sink), params(params) {
    if (this->sink == nullptr) {
        throw std::invalid_argument("Sink cannot be null");
    }
    if (this->sink == nullptr) {
        throw std::invalid_argument("Encoder Params cannot be null");
    }
}

bool Writer::isUsed() const {
    return _isUsed;
}

void Writer::requireNotUsed() const {
}

Sink* Writer::write(JsonString* element) {
    requireNotUsed();
    _isUsed = true;

    writeString(element);

    return sink;
}

void Writer::writeString(JsonString* string) {
    sink->write(QUOTES)->write(string->getValue());
}

void Writer::appendIndentation() {
    for (int i = 0; i < indentation; ++i) {
        sink->write(INDENTATION);
    }
}
