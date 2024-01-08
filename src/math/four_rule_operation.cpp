#include "four_rule_operation.h"

int lzx0626::add(int num1, int num2) {
    return num1 + num2;
}

int lzx0626::sub(int num1, int num2) {
    return num1 - num2;
}

int lzx0626::mul(int num1, int num2) {
    return num1 * num2;
}

int lzx0626::div(int num1, int num2) {
    if (0 == num2)
        throw std::out_of_range("除数不能为0.");

    return num1 / num2;
}
