#pragma once

#include <iostream>
#include <cstring>
namespace s {
    class String {
    private:
        char *entry;
        size_t length;
    public:
        String();
        explicit String(const char*str);
        String(const String& str);
        String& operator=(const String& str);
        String& operator+=(const String& str);
        String operator+(const String& str);
        char& operator[](const size_t& index);
        const char& operator[](const size_t& index) const;
        bool operator>(const String& str) const;
        bool operator<(const String& str) const;
        bool operator==(const String& str) const;
        size_t find(const char& ch) const;
        size_t len() const;
        char& at(const size_t& index);
        ~String();
        const char* c_str() const;
    };
    std::ostream& operator<<(std::ostream& out, const String& s);
    std::istream& operator>>(std::istream& in, String& s);
}