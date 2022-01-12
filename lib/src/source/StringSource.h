#ifndef JSON_LAB_STRINGSOURCE_H
#define JSON_LAB_STRINGSOURCE_H

#include <string>
#include "Source.h"

class StringSource : public Source {
    private:
    std::string source;
    int index = 0;
    int limit;

    public:
    void prev() override;
    explicit StringSource(std::string source);

    private:
    char obtainNextCharOrEof() override;
    void _close() override;
};

#endif