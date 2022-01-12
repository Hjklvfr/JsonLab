cmake_minimum_required(VERSION 3.8)

project(JsonLabLib)

set(CPP_FILES
        include/json_lab/JsonLab.h
        include/json_lab/JsonLabBuilder.h
        include/json_lab/MutableDecoderParams.h
        include/json_lab/MutableEncoderParams.h
        include/json_lab/MutableEncoderParams.cpp
        src/decode/DecoderParams.cpp
        src/decode/DecoderParams.h
        src/decode/MutableDecoderParams.cpp
        src/decode/parser/ElementBuilder.h
        src/decode/parser/ElementBuilder.cpp
        src/decode/parser/JsonParser.h
        src/decode/parser/JsonParser.cpp
        src/decode/parser/JsonArrayParser.h
        src/decode/parser/JsonArrayParser.cpp
        src/decode/parser/JsonMemberParser.h
        src/decode/parser/JsonMemberParser.cpp
        src/decode/parser/JsonNumberParser.h
        src/decode/parser/JsonNumberParser.cpp
        src/decode/parser/JsonObjectParser.h
        src/decode/parser/JsonObjectParser.cpp
        src/decode/parser/JsonStringParser.h
        src/decode/parser/JsonStringParser.cpp
        src/decode/parser/JsonValueParser.h
        src/decode/parser/JsonValueParser.cpp
        src/decode/parser/JsonParserFactory.h
        src/decode/parser/JsonParserFactory.cpp
        src/decode/parser/LoggedParser.h
        src/decode/parser/LoggedParser.cpp
        src/decode/parser/LoggedVisitor.h
        src/decode/parser/LoggedVisitor.cpp
        src/decode/parser/Parser.h
        src/decode/parser/ParserState.h
        src/decode/parser/Visitor.h
        src/encode/EncoderParams.h
        src/encode/EncoderParams.cpp
        src/encode/writer/JsonWriterFactory.h
        src/encode/writer/JsonWriterFactory.cpp
        src/encode/writer/Writer.h
        src/encode/writer/Writer.cpp
        src/entities/JsonArray.h
        src/entities/JsonArray.cpp
        src/entities/JsonBool.h
        src/entities/JsonBool.cpp
        src/entities/JsonElement.h
        src/entities/JsonElement.cpp
        src/entities/JsonMember.h
        src/entities/JsonMember.cpp
        src/entities/JsonNull.h
        src/entities/JsonNull.cpp
        src/entities/JsonNumber.h
        src/entities/JsonNumber.cpp
        src/entities/JsonObject.h
        src/entities/JsonObject.cpp
        src/entities/JsonString.h
        src/entities/JsonString.cpp
        src/entities/JsonValue.h
        src/rules/Syntax.h
        src/sink/FileSink.cpp
        src/sink/FileSink.h
        src/sink/Sink.cpp
        src/sink/Sink.h
        src/sink/LoggedSink.cpp
        src/sink/LoggedSink.h
        src/sink/StringSink.cpp
        src/sink/StringSink.h
        src/source/FileSource.cpp
        src/source/FileSource.h
        src/source/Source.cpp
        src/source/Source.h
        src/source/LoggedSource.cpp
        src/source/LoggedSource.h
        src/source/StringSource.cpp
        src/source/StringSource.h
        src/_utils/CheckExtensions.h
        src/_utils/ClassExtensions.h
        src/_utils/ExceptionsExtensions.h
        src/_utils/LinkedMap.h
        src/_utils/StringBuilder.cpp
        src/_utils/StringBuilder.h
        src/_utils/StringUtils.cpp
        src/_utils/StringUtils.h
)

include_directories(JsonLabLib PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include/json_lab)
include_directories(JsonLabLib PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)
include_directories(JsonLabLib PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/_utils)

add_library(JsonLabLib STATIC ${CPP_FILES})

target_link_libraries(JsonLabLib ${CONAN_LIBS})