/**
 * @file queue.h
 * @author lzx0626 (2065666169@qq.com)
 * @brief 队列类的头文件
 * @version 1.0
 * @date 2024-01-09
 *
 * Copyright (c) 2023 电子科技大学 刘治学
 *
 */

#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <iostream>

#include "arraylist.h"

namespace lzx0626 {

/**
 * @brief 我自己的队列，底层用数组实现的列表维护
 */
template <class value_type>
class queue {
public:
    /**
     * @brief 定义一些类型别名
     */
    using pointer = value_type*;
    using reference = value_type&;
    using constref = const value_type&;

public:
    /**
     * @brief 默认构造函数
     */
    queue() = default;

    /**
     * @brief 默认析构函数
     */
    ~queue() = default;

    /**
     * @brief 拷贝构造，由于list中含有指针，还是写一个吧(虽然我直到可以不用写)
     */
    queue(queue<value_type>& other) { *this = other; }

    /**
     * @brief 对应的拷贝赋值
     */
    queue<value_type>& operator=(queue<value_type>& other) {
        list = other.list;
        return *this;
    }

public:
    /**
     * @brief 入队列
     * @param val，需要入队列的元素的值
     */
    void push(constref val) { list.push_back(val); }

    /**
     * @brief 出队列
     */
    value_type pop() { return list.remove(0); }

    /**
     * @brief 返回队列顶元素的值
     * @return value_type类型队列顶元素的值
     */
    value_type peek() { return list.get(0); }

    /**
     * @brief 判断是否为空
     * @return bool类型，空为真
     */
    bool isEmpty() { return list.isEmpty(); }

private:
    /**
     * @brief 底层采用composition(复合)维护一个双向链表
     */
    arraylist<value_type> list;
};

}  // namespace lzx0626

#endif
