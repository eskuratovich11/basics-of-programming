#include <Matrix.hpp>

Matrix::Matrix(int width, int height) : width(width), height(height) {
    if (width <= 0 || height <= 0) {
        std::cerr << "Incorrect agrs" << std::endl;
        throw std::exception();
    }
    this->mtrx = new int *[width];
    for (int i = 0; i < width; i++) {
        this->mtrx[i] = new int[height];
    }
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            mtrx[i][j] = 0;
        }
    }
}
Matrix::~Matrix() {
    this->clear();
}

Matrix::Matrix(const Matrix &matrix) {
    swap(matrix);
}

Matrix &Matrix::operator=(const Matrix &matrix) {
    this->clear();
    this->swap(matrix);

    return *this;
}

void Matrix::swap(const Matrix &matrix) {
    this->width = matrix.width;
    this->height = matrix.height;
    this->mtrx = new int*[width];
    for (int i = 0; i < width; i++) {
        this->mtrx[i] = new int[height];
        for (int j = 0; j < height; j++) {
            mtrx[i][j] = matrix.mtrx[i][j];
        }
    }
}

void Matrix::clear() {
    for (int i = 0; i < width; i++) {
        delete[] this->mtrx[i];
    }
    delete[] this->mtrx;
    this->width = 0;
    this->height = 0;
}

void Matrix::print() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            std::cout << mtrx[j][i] << " ";
        }
        std::cout << std::endl;
    }
}

int &Matrix::element_at(int x, int y) {
    if(x>=width || y >= height){
        std::cerr << "Incorrect args" << std::endl;
        throw std::exception();
    }
    return this->mtrx[x][y];
}
