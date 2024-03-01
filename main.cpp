#include <iostream>
#include <Matrix.hpp>

int main() {
    Matrix<2,2> m;
    // x1 x2
    // x3 x4
    std::cin >> m;
    Matrix<2,2> m2;
    // x1 x2
    // x3 x4
    std::cin >> m2;
    std::cout << "plus\n" << (m+m2) << "\nmult\n" << (m*m2) << '\n';
    m(0,0) = 0;
    std::cout << (++m) << '\n';
    std::cout << "determinant: " << m.determinant() << '\n';
    return 0;
}
