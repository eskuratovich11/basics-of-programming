#pragma once

#include <iostream>

class Matrix {
private:
    int width, height;
    void swap(const Matrix& m);
    void clear();
    int **mtrx;
public:
    Matrix() = delete;
    Matrix(int width, int height);
    ~Matrix();
    Matrix(const Matrix &matrix);
    Matrix &operator=(const Matrix &matrix);
    int& element_at(int x, int y);
    void print();
};