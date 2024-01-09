#include <iostream>

#include "operator.h"

void test1();
void test2();
void test3();
void test4();

int main() {
    test1();
    test2();
    test3();
    test4();

    return 0;
}

void test1() {
    std::cout << lzx0626::add(1, 2) << std::endl;
}

void test2() {
    std::cout << lzx0626::sub(1, 2) << std::endl;
}

void test3() {
    std::cout << lzx0626::mul(1, 2) << std::endl;
}

void test4() {
    std::cout << lzx0626::div(1, 2) << std::endl;

    try {
        lzx0626::div(2, 0);
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}
