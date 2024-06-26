#include <iostream>

#include "arraylist.h"

template <typename value_type>
void print_arraylist(lzx0626::arraylist<value_type> &array);

void test_constructor();

void test_insert();

void test_remove();

void test_set();

void test_get_operator();

int main()
{
    test_constructor();
    // test_insert();
    // test_remove();
    // test_set();
    // test_get_operator();

    return 0;
}

template <typename value_type>
void print_arraylist(lzx0626::arraylist<value_type> &array)
{
    array.traverse([](value_type &val)
                   { std::cout << val << ' '; });
    std::cout << std::endl;
}

void test_constructor()
{
    lzx0626::arraylist<int> al{1, 2, 3, 4, 5, 6};
    auto al2(al);

    std::cout << "al2: " << std::endl;
    print_arraylist(al2);

    std::cout << "al1: " << std::endl;
    print_arraylist(al);
}

void test_insert()
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

    al.insert(100, -1);
    print_arraylist(al);
}

void test_remove()
{
    lzx0626::arraylist<int> al{1, 2, 3, 4, 5, 6};
    print_arraylist(al);

    std::cout << al.remove(2) << std::endl;
    print_arraylist(al);

    std::cout << al.pop_back() << std::endl;
    print_arraylist(al);

    // 测试弹出size的位置
    al.remove(al.size());
}

// 这个接口的测试需要capacity是共有的，但是实际上不允许，所以我注释掉了，测试成功，需要重新测试把私有改为共有即可
// void test_resize() {
//     // 测试一下缩容是否正确
//     lzx0626::arraylist<int> al{1, 2, 3, 4, 5, 6};
//     print_arraylist(al);
//     std::cout << al.size() << ' ' << al.capacity << std::endl;

//     // 全给他弹完咯
//     for (int i = al.size(); i > 0; --i) {
//         al.pop_back();
//         std::cout << al.size() << ' ' << al.capacity << std::endl;
//     }
// }

void test_set()
{
    lzx0626::arraylist<int> al{1, 2, 3, 4, 5, 6};
    print_arraylist(al);

    al.set(0, 100);
    print_arraylist(al);

    al.set(5, 97);
    print_arraylist(al);

    // 越界
    al.set(7, 101);
}

void test_get_operator()
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

    al[1] = 100;
    print_arraylist(al);

    std::cout << al[6] << std::endl;
}
