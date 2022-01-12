#ifndef JSON_LAB_FILESOURCE_H
#define JSON_LAB_FILESOURCE_H

#include <iostream>
#include <fstream>
#include "Source.h"

class FileSource : public Source {
    private:
    std::ifstream file;
    char obtainNextCharOrEof() override;
    void _close() override;

    public:
    void prev() override;
    FileSource(const std::string& path);
};

#endif