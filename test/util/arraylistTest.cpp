#include <gtest/gtest.h>
#include <iostream>

#include "arraylist.h"

template <typename value_type>
void print_arraylist(lzx0626::arraylist<value_type> &array);

/**
 * @brief 测试构造函数
 *
 */
TEST(arraylistTest, constructorTest)
{
    lzx0626::arraylist<int> al{1, 2, 3, 4, 5, 6};
    auto al2(al);

    std::cout << "al2: " << std::endl;
    print_arraylist(al2);

    std::cout << "al1: " << std::endl;
    print_arraylist(al);
}

/**
 * @brief 测试插入
 *
 */
TEST(arraylistTest, insertTest)
{
    lzx0626::arraylist<int> al{1, 2, 3, 4, 5, 6};
    print_arraylist(al);

    // 测试在末尾插入
    al.insert(6, 57);
    print_arraylist(al);

    al.insert(0, 100);
    print_arraylist(al);

    al.insert(3, 101);
    print_arraylist(al);
}

/**
 * @brief 测试移出
 *
 */
TEST(arraylistTest, removeTest)
{
    lzx0626::arraylist<int> al{1, 2, 3, 4, 5, 6};
    print_arraylist(al);

    std::cout << al.remove(2) << std::endl;
    print_arraylist(al);

    std::cout << al.pop_back() << std::endl;
    print_arraylist(al);
}

/**
 * @brief 测试设置
 *
 */
TEST(arraylistTest, setTest)
{
    lzx0626::arraylist<int> al{1, 2, 3, 4, 5, 6};
    print_arraylist(al);

    al.set(0, 100);
    print_arraylist(al);

    al.set(5, 97);
    print_arraylist(al);
}

/**
 * @brief 测试操作符[]
 *
 */
TEST(arraylistTest, getOperatorTest)
{
    lzx0626::arraylist<int> al{1, 2, 3, 4, 5, 6};
    print_arraylist(al);

    std::cout << "test get" << std::endl;

    std::cout << al.get(0) << std::endl; // 修改不了，因为返回的是一个右值，如果用一个变量接受就进行了一次拷贝
    std::cout << al.get(5) << std::endl;
    // std::cout << al.get(6) << std::endl;

    std::cout << std::endl
              << "test operator[]" << std::endl;

    std::cout << al[0] << std::endl;
    EXPECT_EQ(al[0], 1);

    al[1] = 100;
    std::cout << al[1] << std::endl;
    EXPECT_EQ(al[1], 100);
}

template <typename value_type>
void print_arraylist(lzx0626::arraylist<value_type> &array)
{
    array.traverse([](value_type &val)
                   { std::cout << val << ' '; });
    std::cout << std::endl;
}
