#ifndef JSON_LAB_STRINGBUILDER_H
#define JSON_LAB_STRINGBUILDER_H

#include <string>

class StringBuilder {
    private:
    std::string str;

    public:
    bool isEmpty() const;
    bool isNotEmpty() const;
    int size() const;
    bool isBlank() const;
    bool isNotBlank() const;
    void append(const std::string& s);
    std::string toString();
    void clear();
    std::string extract();
};

#endif