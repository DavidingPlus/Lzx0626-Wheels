#include <iostream>

#include "stack.h"

void test1();

int main()
{
    test1();

    return 0;
}

void test1()
{
    lzx0626::stack<int> ms;
    std::cout << "ms: " << (ms.isEmpty() ? "empty" : "not empty") << std::endl;

    ms.push(1);
    ms.push(2);
    ms.push(3);

    std::cout << ms.get() << std::endl;
    std::cout << ms.pop() << std::endl;
    std::cout << ms.get() << std::endl;

    std::cout << "ms: " << (ms.isEmpty() ? "empty" : "not empty") << std::endl;

    std::cout << std::endl
              << "-----------------------------------" << std::endl
              << std::endl;

    auto ms2 = ms;
    std::cout << "ms2: " << (ms.isEmpty() ? "empty" : "not empty") << std::endl;

    ms.push(100);

    std::cout << ms.get() << std::endl;
    std::cout << ms.pop() << std::endl;
    std::cout << ms.get() << std::endl;

    std::cout << "ms2: " << (ms.isEmpty() ? "empty" : "not empty") << std::endl;
}
