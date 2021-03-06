#ifndef JSON_LAB_CHECKEXTENSIONS_H
#define JSON_LAB_CHECKEXTENSIONS_H
#include <iostream>
#include <string>
#include <cerrno>
#include <utility>
#include <string>
#include <exception>

void checkNotNull(void* value, const std::string& msg = "Expected non null value") {
    if (value == nullptr) {
        throw std::invalid_argument(msg);
    }
}

#endif