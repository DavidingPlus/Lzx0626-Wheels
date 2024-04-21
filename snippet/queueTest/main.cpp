#include <iostream>

#include "queue.h"

void test1();

int main()
{
    test1();

    return 0;
}

void test1()
{
    lzx0626::queue<int> mq;
    std::cout << "mq: " << (mq.isEmpty() ? "empty" : "not empty") << std::endl;

    mq.push(1);
    mq.push(2);
    mq.push(3);

    std::cout << mq.peek() << std::endl;
    std::cout << mq.pop() << std::endl;
    std::cout << mq.peek() << std::endl;

    std::cout << "mq: " << (mq.isEmpty() ? "empty" : "not empty") << std::endl;

    std::cout << std::endl
              << "-----------------------------------" << std::endl
              << std::endl;

    auto mq2 = mq;
    std::cout << "mq2: " << (mq.isEmpty() ? "empty" : "not empty") << std::endl;

    mq.push(100);

    std::cout << mq.peek() << std::endl;
    std::cout << mq.pop() << std::endl;
    std::cout << mq.peek() << std::endl;

    std::cout << "mq2: " << (mq.isEmpty() ? "empty" : "not empty") << std::endl;
}
