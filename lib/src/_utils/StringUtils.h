#ifndef JSON_LAB_STRINGUTILS_H
#define JSON_LAB_STRINGUTILS_H

#include <sstream>
#include <string>
#include <algorithm>
#include <functional>
#include <cctype>
#include <locale>

std::string to_string(char ch);

std::string to_string(const char* chars);

std::string repeat(const std::string& what, int items);

std::string repeat(char what, int items);

std::string to_escape_sequence(char ch, bool addNumericCode = false);

bool is_whitespace(unsigned char uch);

bool is_whitespace(char ch);

int is_whitespace(int ch);

bool is_blank(const std::string& str);

std::string& ltrim(std::string& s);

std::string& rtrim(std::string& s);

std::string& trim(std::string& s);

#endif