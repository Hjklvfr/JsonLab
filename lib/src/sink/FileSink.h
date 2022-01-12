#ifndef JSON_LAB_FILESINK_H
#define JSON_LAB_FILESINK_H


#include <fstream>
#include "Sink.h"

class FileSink : public Sink {
private:
    std::ofstream file;

public:
    explicit FileSink(std::string& path);
protected:
    void _write(const std::string& str) override;
    void _write(char ch) override;
    void _close() override;
};


#endif
