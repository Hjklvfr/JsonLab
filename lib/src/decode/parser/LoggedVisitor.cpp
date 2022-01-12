#include <plog/Log.h>
#include "LoggedVisitor.h"

LoggedVisitor::LoggedVisitor(Visitor& visitor, plog::Severity logLevel) : visitor(visitor), logLevel(logLevel) {}

void LoggedVisitor::onNumber(std::string value) {
    std::ostringstream oss;
    oss << "Number: " << value;
    PLOG(logLevel) << oss.str();
    visitor.onNumber(value);
}

void LoggedVisitor::onString(std::string value) {
    std::ostringstream oss;
    oss << "String: " << value;
    PLOG(logLevel) << oss.str();
    visitor.onString(value);
}

void LoggedVisitor::onBool(bool value) {
    std::ostringstream oss;
    oss << "Bool: " << value;
    PLOG(logLevel) << oss.str();
    visitor.onBool(value);
}

void LoggedVisitor::onNull() {
    std::ostringstream oss;
    oss << "Null";
    PLOG(logLevel) << oss.str();
    visitor.onNull();
}

void LoggedVisitor::onObjectStart() {
    std::ostringstream oss;
    oss << "ObjectStart";
    PLOG(logLevel) << oss.str();
    visitor.onObjectStart();
}

void LoggedVisitor::onObjectMemberStart() {
    std::ostringstream oss;
    oss << "ObjectMemberStart";
    PLOG(logLevel) << oss.str();
    visitor.onObjectMemberStart();
}

void LoggedVisitor::onObjectMemberEnd() {
    std::ostringstream oss;
    oss << "ObjectMemberEnd";
    PLOG(logLevel) << oss.str();
    visitor.onObjectMemberEnd();
}

void LoggedVisitor::onObjectEnd() {
    std::ostringstream oss;
    oss << "ObjectEnd";
    PLOG(logLevel) << oss.str();
    visitor.onObjectEnd();
}

void LoggedVisitor::onArrayStart() {
    std::ostringstream oss;
    oss << "ArrayStart";
    PLOG(logLevel) << oss.str();
    visitor.onArrayStart();
}

void LoggedVisitor::onArrayEnd() {
    std::ostringstream oss;
    oss << "ArrayEnd";
    PLOG(logLevel) << oss.str();
    visitor.onArrayEnd();
}
