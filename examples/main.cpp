#include <iostream>
#include "examples/Integer.h"

int main() {
    Integer a(2);
    std::cout << a.value() << std::endl;
    a.setValue(3);
    std::cout << a.value() << std::endl;
    return 0;
}