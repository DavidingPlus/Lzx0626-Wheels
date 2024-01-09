#include <gtest/gtest.h>

#include <iostream>

#include "queue.h"

/**
 * @brief 测试1
 *
 */
TEST(queueTest, queueTest1) {
    lzx0626::queue<int> mq;

    EXPECT_EQ(mq.isEmpty(), true);
    std::cout << "mq: " << (mq.isEmpty() ? "empty" : "not empty") << std::endl;

    mq.push(1);
    mq.push(2);
    mq.push(3);

    std::cout << mq.peek() << std::endl;
    std::cout << mq.pop() << std::endl;
    std::cout << mq.peek() << std::endl;

    EXPECT_EQ(mq.isEmpty(), false);
    std::cout << "mq: " << (mq.isEmpty() ? "empty" : "not empty") << std::endl;

    std::cout << std::endl
              << "-----------------------------------" << std::endl
              << std::endl;

    auto mq2 = mq;

    EXPECT_EQ(mq.isEmpty(), false);
    std::cout << "mq2: " << (mq.isEmpty() ? "empty" : "not empty") << std::endl;

    mq.push(100);

    std::cout << mq.peek() << std::endl;
    std::cout << mq.pop() << std::endl;
    std::cout << mq.peek() << std::endl;

    EXPECT_EQ(mq.isEmpty(), false);
    std::cout << "mq2: " << (mq.isEmpty() ? "empty" : "not empty") << std::endl;
}
