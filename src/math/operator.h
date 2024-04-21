/**
 * @file operator.h
 * @author DavidingPlus (2065666169@qq.com)
 * @brief 运算符相关函数头文件（用作测试）
 * @version 1.0
 * @date 2024-01-09
 *
 * Copyright (c) 2023 电子科技大学 刘治学
 *
 */

#ifndef _OPERATOR_H_
#define _OPERATOR_H_

#include <exception>
#include <iostream>

namespace lzx0626
{

    /**
     * @brief 加法运算
     *
     * @param num1 数1
     * @param num2 数2
     * @return auto 类型自动推导
     */
    auto add(auto num1, auto num2) { return num1 + num2; }

    /**
     * @brief 减法运算
     *
     * @param num1 数1
     * @param num2 数2
     * @return auto 类型自动推导
     */
    auto sub(auto num1, auto num2) { return num1 - num2; }

    /**
     * @brief 乘法运算
     *
     * @param num1 数1
     * @param num2 数2
     * @return auto 类型自动推导
     */
    auto mul(auto num1, auto num2) { return num1 * num2; }

    /**
     * @brief 除法运算
     *
     * @param num1 数1
     * @param num2 数2
     * @return auto 类型自动推导
     */
    auto div(auto num1, auto num2)
    {
        if (0 == num2)
            throw std::out_of_range("除数不能为0!");
        return num1 / num2;
    }

} // namespace lzx0626

#endif
