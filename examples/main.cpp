#include <iostream>
#include "examples/Integer.h"

int main() {
    Integer a(2);
    Integer b(4);
    a = b;

    b = Integer(9);
    std::cout << a.value() << std::endl;
    std::cout << b.value() << std::endl;
    return 0;
}