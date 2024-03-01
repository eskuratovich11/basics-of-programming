#pragma once

#include <iostream>

template<size_t W, size_t H>
class Matrix {
private:
    int grid[W][H] {0};
public:
    Matrix() = default;
    Matrix(const Matrix<W,H>&matrix);
    Matrix<W,H>& operator+=(const Matrix<W,H>&matrix);
    Matrix<W,H>& operator=(const Matrix<W,H>&matrix);
    Matrix<W,H> operator+(const Matrix<W,H>&matrix);
    template<size_t NW>
    Matrix<NW,H> operator*(const Matrix<NW,W>&matrix);
    int& operator()(const size_t&x,const size_t&y);
    const int& operator()(const size_t&x,const size_t&y) const;
    Matrix<W,H>& operator++();
    int determinant();
    ~Matrix() = default;
};
int chet(const int&x1,const int&x2,const int&x3){
    int inv = 0;
    if(x2 < x1)inv++;
    if(x3 < x1)inv++;
    if(x3 < x2)inv++;
    return inv%2==0?1:-1;
}

template<size_t W, size_t H>
int Matrix<W, H>::determinant() {
    if(W!=H || W == 0 || W>3)throw std::exception();
    if(W==1)return this->grid[0][0];
    if(W==2)return this->grid[0][0]*this->grid[1][1] - grid[0][1]*this->grid[1][0];
    if(W==3){
        int d = 0;
        for(int x1 = 0;x1<3;++x1){
            for(int x2 = 0;x2<3;++x2){
                for(int x3 = 0;x3<3;++x3){
                    if(x1 != x2 && x1 != x3 && x2!= x3){
                        d += chet(x1,x2,x3)* this->operator()(x1,0) * this->operator()(x2,1) * this->operator()(x3,2);
                    }
                }
            }
        }
        return d;
    }
}

template<size_t W, size_t H>
Matrix<W, H> &Matrix<W, H>::operator++() {
    for(size_t x = 0;x<W;++x){
        for(size_t y = 0;y<H;++y){
            this->grid[x][y]++;
        }
    }
    return *this;
}

template<size_t W, size_t H>
template<size_t NW>
Matrix<NW, H> Matrix<W, H>::operator*(const Matrix<NW, W> &matrix) {
    Matrix<NW, H> n;
    for(size_t y = 0;y<H;++y){
        for(size_t xx = 0;xx<NW;++xx){
            for(size_t x = 0;x<W;++x){
                n(xx,y)+= this->grid[x][y]*matrix(xx,x);
            }
        }
    }
    return n;
}

template<size_t W, size_t H>
Matrix<W, H> &Matrix<W, H>::operator=(const Matrix<W, H> &matrix) {
    for (size_t i = 0; i < W; ++i) {
        std::copy(matrix.grid[i],matrix.grid[i]+H,grid[i]);
    }
    return *this;
}

template<size_t W, size_t H>
Matrix<W, H> Matrix<W, H>::operator+(const Matrix<W, H> &matrix) {
    Matrix<W,H> copy(*this);
    return copy += matrix;
}

template<size_t W, size_t H>
const int &Matrix<W, H>::operator()(const size_t &x, const size_t &y) const {
    return this->grid[x][y];
}

template<size_t W, size_t H>
int &Matrix<W, H>::operator()(const size_t &x, const size_t &y) {
    return this->grid[x][y];
}

template<size_t W, size_t H>
std::istream& operator >>(std::istream&in,Matrix<W,H>& matrix){
    int n;
    for(size_t y = 0;y<H;++y){
        for(size_t x = 0;x<W;++x) {
            in >> n;
            matrix(x,y) = n;
        }
    }
    return in;
}
template<size_t W, size_t H>
std::ostream& operator <<(std::ostream&out,const Matrix<W,H>& matrix){
    for(size_t y = 0;y<H;++y){
        for(size_t x = 0;x<W;++x) {
            out << matrix(x,y) << "\t";
        }
        out << '\n';
    }
    return out;
}

template<size_t W, size_t H>
Matrix<W,H> &Matrix<W, H>::operator+=(const Matrix<W,H> &matrix) {
    for(size_t x = 0;x<W;++x){
        for(size_t y = 0;y<H;++y){
            this->grid[x][y] += matrix.grid[x][y];
        }
    }
    return *this;
}

template<size_t W, size_t H>
Matrix<W, H>::Matrix(const Matrix<W,H> &matrix) {
    for (size_t i = 0; i < W; ++i) {
        std::copy(matrix.grid[i],matrix.grid[i]+H,grid[i]);
    }
}
