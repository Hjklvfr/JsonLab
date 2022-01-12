#ifndef JSON_LAB_STRINGSINK_H
#define JSON_LAB_STRINGSINK_H


#include <string>
#include <sstream>
#include "Sink.h"

class StringSink : public Sink {
private:
    std::stringstream ss;
protected:
    void _write(const std::string& str) override;
    void _write(char ch) override;
    void _close() override;
public:
    std::string toString();
};


#endif
