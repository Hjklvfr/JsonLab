#ifndef JSON_LAB_JSONLAB_H
#define JSON_LAB_JSONLAB_H

#include <plog/Severity.h>
#include "../../src/encode/writer/JsonWriterFactory.h"
#include "../../src/decode/parser/JsonParserFactory.h"
#include "../../src/sink/StringSink.h"
#include "../../src/source/StringSource.h"
#include "../../src/source/FileSource.h"
#include "../../src/entities/JsonValue.h"
#include "../../src/decode/parser/Visitor.h"

// LAB 4

class JsonLab {
    plog::Severity logLevel = plog::none;
    std::string logFileName = "";
    JsonWriterFactory* jsonWriterFactory;
    JsonParserFactory* jsonParserFactory;

    Sink* applyLogging(Sink* sink);
    Source* applyLogging(Source* sink);
    Visitor* applyLogging(Visitor* sink);
    Parser* applyLogging(Parser* parser);

    public:
    JsonLab(JsonWriterFactory* jsonWriterFactory, JsonParserFactory* jsonParserFactory, plog::Severity logLevel, std::string logFileName = "");
    JsonLab();

    std::string jsonStringToString(JsonString* string);
    Sink* jsonStringToSink(JsonString* string, Sink* sink);
    void parseFromSource(Source* source, Visitor* visitor);
    JsonValue* jsonTreeFromSource(Source* source);
    JsonValue* jsonTreeFromString(std::string json);

    virtual ~JsonLab();
};

#endif