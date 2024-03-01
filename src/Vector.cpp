#include <Vector.hpp>

Vector::Vector() : bitLength(0),intLength(0),arr(new unsigned int[0]){
}

Vector::~Vector() {
    delete[] arr;
}
bool getNBit(const unsigned int& i,const unsigned int& n){
    unsigned int num = std::pow(2u,n);
    return (i&num)==num;
}
void setNBit(unsigned int& i,const unsigned int& n,const bool& value){
    unsigned int num = std::pow(2u,n);
    i = i&(~num);
    if(!value)return;
    i+= num;
}
bool Vector::get(const size_t &index) {
    if(index >= bitLength)throw std::exception();
    return getNBit(arr[index/32],index%32);
}

void Vector::set(const size_t &index, const bool &value) {
    if(index >= bitLength)throw std::exception();
    setNBit(arr[index/32],index%32,value);
}

size_t Vector::size() {
    return bitLength;
}
size_t ceil(size_t x, size_t y)
{
    return (x - 1ull) / y + 1ull;
}
void Vector::addToEnd(const bool &value) {
    ++bitLength;
    updateLength();
    set(bitLength-1,value);
}

void Vector::updateLength() {
    if(ceil(bitLength,32ull)>intLength){
        auto*newArr = new unsigned int [++intLength];
        std::copy(arr,arr+intLength-1,newArr);
        delete[] arr;
        arr = newArr;
    }
}

void Vector::insert(const size_t &index, const bool &value) {
    if(index >= bitLength)throw std::exception();
    ++bitLength;
    updateLength();
    for(size_t i = bitLength-1;i>index;--i){
        set(i,get(i-1));
    }
    set(index,value);
}

void Vector::erase(const size_t &index) {
    if(index >= bitLength)throw std::exception();
    for(size_t i = index;i<bitLength-1;++i){
        set(i,get(i+1));
    }
    --bitLength;
}
