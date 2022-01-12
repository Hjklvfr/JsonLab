
#include "../lib/src/source/StringSource.h"
#include "../lib/include/json_lab/MutableDecoderParams.h"
#include "../lib/src/decode/parser/ElementBuilder.h"
#include <gtest/gtest.h>
#include "../lib/src/decode/parser/JsonParser.h"
#include <iostream>

// LAB 5

namespace ParserTest {

    std::string TEST_STRING = "\"tupa string\"";
    std::string TEST_NUMBER = "123";
    std::string TEST_NULL = "null";
    std::string TEST_TRUE = "true";
    std::string TEST_FALSE = "false";
    std::string TEST_OBJECT = "{\"name\": \"Steve\", \"age\": 21, \"isMale\": true}";
    std::string TEST_ARRAY = "[\"tupa string\", 1337, {\"name\": \"Steve\", \"age\": 21, \"isMale\": true}]";

    JsonValue* getParsed(std::string json) {
        Source* source = new StringSource(json);

        MutableDecoderParams* params = new MutableDecoderParams();
        params->setTrim(true);
        params->setKeepBlankStringValues(false);

        ElementBuilder* visitor = new ElementBuilder();

        Parser* parser = new JsonParser(source, params, (Visitor*) visitor);

        parser->parse();

        JsonValue* value = visitor->getRoot();

        return value;
    }

    TEST(String, TEST_STRING_VALUE) {
        std::ostringstream oss;
        getParsed(TEST_STRING)->printTo(oss, 0);
        auto str = oss.str();
        EXPECT_EQ(str, TEST_STRING);
    }

    TEST(Number, TEST_STRING_NUMBER) {
        std::ostringstream oss;
        getParsed(TEST_NUMBER)->printTo(oss, 0);
        auto str = oss.str();
        EXPECT_EQ(str, TEST_NUMBER);
    }

    TEST(Bool, TEST_STRING_TRUE) {
        std::ostringstream oss;
        getParsed(TEST_TRUE)->printTo(oss, 0);
        auto str = oss.str();
        EXPECT_EQ(str, TEST_TRUE);
    }

    TEST(Bool, TEST_STRING_FALSE) {
        std::ostringstream oss;
        getParsed(TEST_FALSE)->printTo(oss, 0);
        auto str = oss.str();
        EXPECT_EQ(str, TEST_FALSE);
    }

    TEST(Null, TEST_STRING_NULL) {
        std::ostringstream oss;
        getParsed(TEST_NULL)->printTo(oss, 0);
        auto str = oss.str();
        EXPECT_EQ(str, TEST_NULL);
    }

    TEST(Object_test, TEST_STRING_OBJECT) {
        std::ostringstream oss;
        getParsed(TEST_OBJECT)->printTo(oss, 0);
        auto str = oss.str();
        EXPECT_EQ(str, TEST_OBJECT);
    }

    TEST(Array, TEST_STRING_ARRAY) {
        std::ostringstream oss;
        getParsed(TEST_ARRAY)->printTo(oss, 0);
        auto str = oss.str();
        EXPECT_EQ(str, TEST_ARRAY);
    }
}