#ifndef JSON_LAB_SOURCE_H
#define JSON_LAB_SOURCE_H

// LAB 3

class Source
{
    private:
    bool _isClose = false;
    bool _isRead = false;

    protected:
    char obtainedChar = 0;
    virtual char obtainNextCharOrEof() = 0;
    virtual void _close() = 0;

    public:
    virtual void prev();
    virtual char nextChar();
    virtual bool hasNext();
    virtual bool close();
    virtual bool isClosed() const;
    virtual bool hasObtainedChar() const;
};


#endif
