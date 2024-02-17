#include <iostream>
#include <BigInt.hpp>
int main() {
    BigInt i("0");
    BigInt i2("0");
    std::cout << "Number 1:";
    std::cin >> i;
    std::cout << "Number 2:";
    std::cin >> i2;
    std::cout << "* " <<(i*i2) << '\n';
    std::cout << "+ " <<(i+i2) << '\n';
    std::cout << "> " <<(i>i2) << '\n';
    std::cout << "< " <<(i<i2) << '\n';
    std::cout << "== " <<(i==i2) << '\n';
    std::cout << "!= " <<(i!=i2) << '\n';
    return 0;
}
