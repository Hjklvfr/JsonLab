#ifndef JSON_LAB_JSONLABBUILDER_H
#define JSON_LAB_JSONLABBUILDER_H

#include "../../src/decode/parser/Visitor.h"
#include "JsonLab.h"
#include "MutableDecoderParams.h"
#include "MutableEncoderParams.h"

class JsonLabBuilder {
    private:
    std::string logFileName;
    plog::Severity logLevel = plog::none;
    MutableDecoderParams* decoderParams = new MutableDecoderParams();
    MutableEncoderParams* encoderParams = new MutableEncoderParams();

    public:
    JsonLabBuilder* setPrettyPrinting(bool beautify = true);

    JsonLabBuilder* keepBlankStringValues(bool keepBlankStringValues = false);

    JsonLabBuilder* setTrim(bool trim = true);

    JsonLabBuilder* setLoggingLevel(plog::Severity level = plog::Severity::debug, std::string logFileName = "");

    JsonLab create();
};

#endif