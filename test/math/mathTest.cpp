#include <gtest/gtest.h>

#include "four_rule_operation.h"

/**
 * @brief 加法测试
 *
 */
TEST(mathTest, addTest) {
    EXPECT_EQ(lzx0626::add(1, 2), 3);
}

/**
 * @brief 减法测试
 *
 */
TEST(mathTest, subTest) {
    EXPECT_EQ(lzx0626::sub(1, 2), -1);
}

/**
 * @brief 乘法测试
 *
 */
TEST(mathTest, mulTest) {
    EXPECT_EQ(lzx0626::mul(1, 2), 2);
}

/**
 * @brief 除法测试
 *
 */
TEST(mathTest, divTest) {
    EXPECT_EQ(lzx0626::div(3, 1), 3);
}
/**
 * @brief 除法失败测试
 *
 */
TEST(mathTest, divFailTest) {
    EXPECT_ANY_THROW(lzx0626::div(3, 0));
}
