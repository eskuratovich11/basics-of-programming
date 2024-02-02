#include <iostream>
#include <Matrix.hpp>

using namespace std;

int main() {
    Matrix matrix(5,3);
    matrix.element_at(0, 0) = 1;

    Matrix matrix_2(matrix);
    Matrix matrix_3 = matrix_2 = matrix;

    matrix_2.element_at(3, 2) = 4;
    matrix_3.element_at(0, 0) = 3;

    matrix.print();
    std::cout <<'\n';
    matrix_2.print();
    std::cout <<'\n';
    matrix_3.print();

    return 0;
}
