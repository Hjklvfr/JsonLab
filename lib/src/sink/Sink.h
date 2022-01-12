#ifndef JSON_LAB_SINK_H
#define JSON_LAB_SINK_H

#include "string"

// LAB 3

class Sink {
private:
    bool _isClosed = false;
protected:
    virtual void _write(const std::string& str) = 0;
    virtual void _write(char ch) = 0;
    virtual void _close() = 0;
public:
    Sink* write(const std::string& str);
    Sink* write(char ch);
    void close();
    bool isClosed();
    void checkNotClosed();
};

#endif
