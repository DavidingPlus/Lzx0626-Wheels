/**
 * @file arraylist.h
 * @author lzx0626 (2065666169@qq.com)
 * @brief 用数组实现的列表类的头文件
 * @version 1.0
 * @date 2024-01-09
 *
 * Copyright (c) 2023 电子科技大学 刘治学
 *
 */

#ifndef _ARRAYLIST_H_
#define _ARRAYLIST_H_

#include <cstring>
#include <exception>
#include <iostream>
#include <string>

namespace lzx0626 {
/**
 * @brief 底层用数组实现的列表类
 */
template <class value_type>
class arraylist {
public:
    /**
     * @brief 定义一些类型别名
     */
    using pointer = value_type *;
    using reference = value_type &;
    using constref = const value_type &;

public:
    /**
     * @brief 默认构造函数
     */
    arraylist() { _init(); }

    /**
     * @brief 带参构造
     * @param list，初始化列表
     */
    arraylist(std::initializer_list<value_type> list) : arraylist() {
        for (constref val : list)
            push_back(val);
    }

    /**
     * @brief 析构函数
     */
    ~arraylist() { delete[] data; }

    /**
     * @brief 带指针，需要些拷贝复制
     * @param array，需要拷贝复制的对象
     */
    arraylist<value_type> &operator=(const arraylist<value_type> &array) {
        // 检测自我赋值
        if (this == &array)
            return *this;

        // 不是先杀掉自己，然后赋值，深拷贝
        _size = array._size;
        capacity = array.capacity;

        auto tmp = data;

        data = new value_type[array.capacity];
        memcpy(data, array.data, sizeof(value_type) * _size);

        delete[] tmp;

        return *this;
    }

    /**
     * @brief 带指针，需要写拷贝构造
     * @param array，需要拷贝构造的对象
     */
    arraylist(const arraylist<value_type> &array) { *this = array; }

public:
    /***********增***********/
    /**
     * @brief 在index的位置插入一个元素
     * @param index，需要插入的位置，注意插入的位置是在缝里插入，所以pos==size的情况是合法的，意思就是在最后的位置插入
     * @param val，插入的元素的值
     */
    void insert(int index, constref val) {
        _check_index(index, "insert");

        // 判断是否需要进行扩容
        if (_size == capacity)
            _resize(2 * capacity);
        // 从最后一个(下标size-1)到index下标都往后移动
        // 第一次插入pos这里为-1，size_t会转化为补码，就会访问非法内存，所以这里pos使用ssize_t类型并且加上pos>0的判断
        for (ssize_t pos = _size - 1; pos > 0 && pos >= index; --pos)
            data[pos + 1] = data[pos];
        // 将新元素插入
        data[index] = val;
        ++_size;
    }

    /**
     * @brief 在数组末尾插入元素
     * @param val，插入的元素的值
     */
    void push_back(constref val) { insert(_size, val); }

    /***********删***********/
    /**
     * @brief 删除指定index位置处的元素并返回
     * @param index，需要删除的元素的下标
     * @return value_type类型的删除的元素的值
     */
    value_type remove(int index) {
        _check_index(index, "remove");

        // 删除元素
        value_type del_val = data[index];

        for (int pos = index; pos < _size - 1; ++pos)
            data[pos] = data[pos + 1];

        data[_size - 1] = (value_type)0;

        // 如果删除之后的大小小于capacity的四分之一，那么我们进行缩容
        if (--_size < capacity / 4)
            _resize(capacity / 2);

        return del_val;
    }

    /**
     * @brief 删除末尾的元素
     * @return value_type类型的删除的元素的值
     */
    value_type pop_back() { return remove(_size - 1); }

    /***********改***********/
    /**
     * @brief 修改index位置的元素值为val
     * @param index，指定的需要修改的元素下标
     * @param val，修改过后的值
     * @return value_type类型的查询到的元素值
     */
    value_type set(int index, constref val) {
        _check_index(index, "set");

        value_type pre_val = data[index];
        data[index] = val;

        return pre_val;
    }

    /***********查***********/
    /**
     * @brief 返回index位置处的元素值
     * @param index，指定需要查询的下标
     * @return value_type类型的查询到的元素值
     */
    value_type get(int index) {
        _check_index(index, "get");

        return data[index];
    }

    /**
     * @brief 肯定需要重载中括号运算符啊，只不过这个中括号返回的是引用，里面的值可以修改
     */
    reference operator[](int index) {
        _check_index(index, "operator []");

        return data[index];
    }

    /***********工具函数***********/
    /**
     * @brief 定义回调函数的类型
     */
    using call_back = void(reference);

    /**
     * @brief 给用户提供遍历容器的接口，怎么遍历通过回调函数指定
     * @param call，函数作为回调函数
     */
    void traverse(call_back call) {
        for (int i = 0; i < _size; ++i)
            call(data[i]);
    }

    /**
     * @brief 提供返回容器元素个数的接口
     * @return size_t类型的数组元素个数
     */
    size_t size() { return _size; }

    /**
     * @brief 判断容器是否为空
     */
    bool isEmpty() { return 0 == _size; }

private:
    /**
     * @brief 对数组进行初始化
     */
    void _init() {
        capacity = INIT_CAP;
        data = new value_type[capacity];
        _size = 0;
    }

    /**
     * @brief 对数组重新进行扩容
     * @param cap，扩充到的大小，一般采取两倍扩容
     */
    void _resize(size_t cap) {  // 开辟一段新空间
        pointer newdata = new value_type[cap];
        // 将原来的数组值
        memcpy(newdata, data, sizeof(value_type) * _size);

        // 更新capacity
        capacity = cap;

        pointer tmp = data;
        data = newdata;
        delete[] tmp;
    }

    /**
     * @brief 写一个函数专门用作进行index下标的异常处理，防止代码冗杂
     * @param index，需要检查的下标
     * @param func_name，函数名称
     */
    void _check_index(int index, std::string func_name) {
        // insert可以是size，但是其他的接口不能用size，这里进行特殊判断
        try {
            bool ret = false;
            if (func_name == "insert")
                ret = index < 0 || index > _size;
            else
                ret = index < 0 || index >= _size;

            if (ret) {
                char exception_str[1024] = {0};
                sprintf(exception_str, "%s postion was out of range.", func_name.c_str());

                throw std::out_of_range(exception_str);
            }
            return;
        } catch (std::out_of_range &e) {
            std::cerr << e.what() << std::endl;
            exit(-1);
        }
    }

private:
    /**
     * @brief 存储数据的数组，这里放一根指针
     */
    pointer data;

    /**
     * @brief 存储数组的大小
     */
    size_t _size;

    /**
     * @brief 存储数组的容量
     */
    size_t capacity;

    /**
     * @brief 定义数组默认初始的容量，由于需要打包为库，这里最好不要使用静态成员变量，否则可能会出现模板声明和定义分离的问题
     */
    const size_t INIT_CAP = 1;
};

}  // namespace lzx0626

#endif
