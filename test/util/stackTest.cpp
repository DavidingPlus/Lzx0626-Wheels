#include <gtest/gtest.h>
#include <iostream>

#include "stack.h"

/**
 * @brief 测试1
 *
 */
TEST(stackTest, stackTest1)
{
    lzx0626::stack<int> ms;

    EXPECT_EQ(ms.isEmpty(), true);
    std::cout << "ms: " << (ms.isEmpty() ? "empty" : "not empty") << std::endl;

    ms.push(1);
    ms.push(2);
    ms.push(3);

    std::cout << ms.get() << std::endl;
    std::cout << ms.pop() << std::endl;
    std::cout << ms.get() << std::endl;

    EXPECT_EQ(ms.isEmpty(), false);
    std::cout << "ms: " << (ms.isEmpty() ? "empty" : "not empty") << std::endl;

    std::cout << std::endl
              << "-----------------------------------" << std::endl
              << std::endl;

    auto ms2 = ms;

    EXPECT_EQ(ms.isEmpty(), false);
    std::cout << "ms2: " << (ms.isEmpty() ? "empty" : "not empty") << std::endl;

    ms.push(100);

    std::cout << ms.get() << std::endl;
    std::cout << ms.pop() << std::endl;
    std::cout << ms.get() << std::endl;

    EXPECT_EQ(ms.isEmpty(), false);
    std::cout << "ms2: " << (ms.isEmpty() ? "empty" : "not empty") << std::endl;
}
