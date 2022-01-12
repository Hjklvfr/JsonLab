#ifndef JSON_LAB_EXCEPTIONEXTENSIONS_H
#define JSON_LAB_EXCEPTIONEXTENSIONS_H

#include <iostream>
#include <string>
#include <cerrno>
#include <utility>
#include <exception>
#include "ClassExtensions.h"

class BaseException : public std::runtime_error {
    protected:
    std::string msg;

    public:
    explicit BaseException(const std::string& msg) : BaseException("BaseException", msg) {}

    protected:
    explicit BaseException(
        const std::string& exceptionName, 
        const std::string& msg
    ) : std::runtime_error(exceptionName + ": " + msg) {
        this->msg = exceptionName + ": " + msg;
    }

    public:
    const char* what() const noexcept override {
        return msg.c_str();
    }

    public:
    virtual ~BaseException() = default;
};

struct UnsupportedOperationException : public BaseException {
    public:
    explicit UnsupportedOperationException(const std::string& msg) : UnsupportedOperationException("UnsupportedOperationException", msg) {}

    protected:
    explicit UnsupportedOperationException(
        const std::string& exceptionName,
        const std::string& msg
    ) : BaseException(exceptionName, msg) {}

    private:
    const char* what() const noexcept override {
        return msg.c_str();
    }
};

struct IllegalStateException : public BaseException {
    public:
    explicit IllegalStateException(const std::string& msg) : IllegalStateException("IllegalStateException", msg) {}

    protected:
    explicit IllegalStateException(
        const std::string& exceptionName,
        const std::string& msg
    ) : BaseException(exceptionName, msg) {}

    private:
    const char* what() const noexcept override {
        return msg.c_str();
    }
};

struct BadCastException : public BaseException {
    public:
    explicit BadCastException(const std::string& msg) : BadCastException("BadCastException", msg) {}

    protected:
    explicit BadCastException(
        const std::string& exceptionName,
        const std::string& msg
    ) : BaseException(exceptionName, msg) {}

    private:
    const char* what() const noexcept override {
        return msg.c_str();
    }
};

#endif