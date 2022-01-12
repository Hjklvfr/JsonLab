#ifndef JSON_LAB_PARSER_H
#define JSON_LAB_PARSER_H

#include "Visitor.h"

// LAB 1

class Parser {
    public:
    virtual bool isUsed() const = 0;
    virtual void requireNotUsed() const = 0;
    virtual Visitor* parse() = 0;
};

#endif
