#include <String.hpp>
namespace s {
    String::~String() {
        delete[] entry;
    }

    String::String() : entry(new char[1]{'\0'}), length(0) {}

    String::String(const char *str) : length(strlen(str)) {
        entry = new char[length + 1];
        std::copy(str, str + length + 1, entry);
    }

    const char *String::c_str() const {
        return entry;
    }

    String::String(const String &str) {
        length = str.length;
        entry = new char[length + 1];
        std::copy(str.entry, str.entry + length + 1, entry);
    }

    String &String::operator=(const String &str) {
        if (this == &str)
            return *this;
        delete[] entry;
        length = str.length;
        entry = new char[length + 1];
        std::copy(str.entry, str.entry + length + 1, entry);
        return *this;
    }

    String &String::operator+=(const s::String &str) {
        char *newEntry = new char[length + str.length + 1];
        std::copy(entry, entry + length, newEntry);
        std::copy(str.entry, str.entry + str.length + 1, newEntry + length);
        delete[] entry;
        entry = newEntry;
        length += str.length;
        return *this;
    }

    String String::operator+(const String &str) {
        String s(*this);
        return s += str;
    }

    char &String::operator[](const size_t &index) {
        return entry[index];
    }

    const char &String::operator[](const size_t &index) const {
        return entry[index];
    }

    bool String::operator>(const String &str) const {
        return length > str.length;
    }

    bool String::operator<(const String &str) const {
        return length < str.length;
    }

    bool String::operator==(const String &str) const {
        return (strcmp(entry,str.entry) == 0);
    }

    size_t String::find(const char &ch) const {
        for (size_t i = 0; i < length; i++) {
            if (entry[i] == ch)return i;
        }
        throw std::exception();
    }

    size_t String::len() const {
        return length;
    }

    char &String::at(const size_t &index) {
        if (index >= length || index == SIZE_MAX)
            throw std::exception();
        return operator[](index);
    }

    std::ostream &operator<<(std::ostream &out, const String &s) {
        out << s.c_str();
        return out;
    }
    std::istream& operator>>(std::istream& in, String& s){
        char ch;
        in >> ch;
        char ar[1] {ch};
        s+=String(ar);
        return in;
    }
}
