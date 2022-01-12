#ifndef JSON_LAB_VISITOR_H
#define JSON_LAB_VISITOR_H

#include <string>

// LAB 1

class Visitor {
    public:
    virtual void onNumber(std::string value) = 0;
    virtual void onString(std::string value) = 0;
    virtual void onBool(bool value) = 0;
    virtual void onNull() = 0;
    virtual void onObjectStart() = 0;
    virtual void onObjectMemberStart() = 0;
    virtual void onObjectMemberEnd() = 0;
    virtual void onObjectEnd() = 0;
    virtual void onArrayStart() = 0;
    virtual void onArrayEnd() = 0;
};

#endif
