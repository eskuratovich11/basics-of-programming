#include <iostream>
#include <Vector.hpp>

int main() {
    Vector v;
    v.addToEnd(false);
    v.addToEnd(false);
    v.addToEnd(false);
    v.addToEnd(false);
    v.addToEnd(true);
    for(size_t i = 0;i<v.size();++i){
        std::cout << v.get(i);
    }
    std::cout <<'\n';

    v.set(0,true);
    v.insert(1,true);
    for(size_t i = 0;i<v.size();++i){
        std::cout << v.get(i);
    }
    std::cout <<'\n';

    v.erase(2);
    v.erase(2);
    for(size_t i = 0;i<v.size();++i){
        std::cout << v.get(i);
    }
    std::cout <<'\n';
    return 0;
}
