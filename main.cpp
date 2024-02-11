#include <iostream>
#include <String.hpp>

using namespace s;

int main() {
    String str1("string_1");
    String str2(str1);
    str1 = str2;
    String str3;
    str3 += (str1+str2);
    std::cout << str3 << '\n';
    str3[0] = '0';
    std::cout << str3 << " " << str3[5] << '\n';
    std::cout << (str3>str1) << " " << (str3<str1) << " " << (str1==str2) << '\n';
    std::cout << str2.find('i') << '\n';
    std::cout << str3.len() << '\n';
    str3.c_str();
    str3.at(0);
    return 0;
}
