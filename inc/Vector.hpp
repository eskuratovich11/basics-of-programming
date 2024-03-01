#pragma once

#include <iostream>
#include <cmath>

class Vector {
private:
    unsigned int* arr;
    size_t bitLength;
    size_t intLength;
    void updateLength();
public:
    Vector();
    bool get(const size_t&index);
    void set(const size_t&index,const bool&value);
    void addToEnd(const bool&value);
    void insert(const size_t&index,const bool&value);
    void erase(const size_t&index);
    size_t size();
    ~Vector();
};

