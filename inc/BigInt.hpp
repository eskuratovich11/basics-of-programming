#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
class BigInt {
private:
    std::string strInt;
    int ctoi(const char&ch);
    char itoc(const int&i);
    bool is_int(const std::string& str);
    BigInt operator*(const char& ch);
public:
    BigInt(const char*i);
    BigInt(const BigInt& bI);
    BigInt& operator+=(const BigInt& bI);
    BigInt& operator*=(const BigInt& bI);
    BigInt operator+(const BigInt& bI);
    BigInt operator*(const BigInt& bI);
    bool operator>(const BigInt& bI);
    bool operator<(const BigInt& bI);
    bool operator==(const BigInt& bI);
    bool operator!=(const BigInt& bI);
    friend std::istream& operator>>(std::istream& in,BigInt& bi);
    char* to_string() const;
};
std::ostream& operator<<(std::ostream& out,const BigInt& bi);

