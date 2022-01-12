#include "../include/json_lab/JsonLab.h"
#include "sink/LoggedSink.h"
#include "decode/parser/LoggedParser.h"
#include "decode/parser/LoggedVisitor.h"

JsonLab::JsonLab(JsonWriterFactory* jsonWriterFactory, JsonParserFactory* jsonParserFactory, plog::Severity logLevel, std::string logFileName = "") 
        : jsonWriterFactory(jsonWriterFactory), jsonParserFactory(jsonParserFactory), logLevel(logLevel), logFileName(logFileName) {
    if (logLevel != plog::none && !logFileName.empty()) {
        plog::init(logLevel, logFileName.c_str());
    }
}

JsonLab::JsonLab() : JsonLab(
    new JsonWriterFactory(new EncoderParams()),
    new JsonParserFactory(new DecoderParams()),
    plog::none,
    ""
) {}

std::string jsonStringToString(JsonString* string) {
    StringSink sink = StringSink();

    jsonStringToSink(string, &sink);
    sink.close();
    return sink.toString();
}

Sink* jsonStringToSink(JsonString* string, Sink* sink) {
    try {
        Sink* loggedSink = applyLogging(sink);
        Writer* writer = JsonWriterFactory->get(loggedSink);
        writer->write(string);
        delete writer;
        return sink;
    } catch(std::exception& ex) {
        sink->close();
        throw ex;
    }
}

void JsonLab::parseFromSource(Source* source, Visitor* visitor) {
    try {
        Source* loggedSource = applyLogging(source);

        Parser* parser = JsonParserFactory->get(loggedSource, visitor);
        parser = applyLogging(parser);

        parser->parse();
        delete parser;
    } catch (std::exception& ex) {
        source->close();
        throw ex;
    }
}

JsonValue* JsonLab::jsonTreeFromString(std::string json) {
    auto source = StringSource(std::move(json));
    return jsonStringFromSource(&source);
}

JsonLab::~JsonLab() {
    delete jsonWriterFactory;
    delete jsonParserFactory;
}

Sink* JsonLab::applyLogging(Sink* sink) {
    if (logLevel != plog::none) {
        return new LoggedSink(*sink, logLevel);
    }
    return sink;
}
Source* JsonLab::applyLogging(Source* source) {
    if (logLevel != plog::none) {
        return new LoggedSource(*source, logLevel);
    }
    return source;
}
Visitor* JsonLab::applyLogging(Visitor* visitor) {
    if (logLevel != plog::none) {
        return new LoggedVisitor(*visitor, logLevel);
    }
    return visitor;
}
Parser* JsonLab::applyLogging(Parser* parser) {
    if (logLevel != plog::none) {
        return new LoggedParser(parser, logLevel);
    }
    return parser;
}
