#include <iostream>
#include "foo.h"
// gcc -c foo.c
// g++ test.cpp foo.o -o test
// ./test

int main() {
    int a = 100;
    int b = 200;
    std::cout << a << " " << b << std::endl;
    swap(&a, &b, sizeof(a));
    std::cout << a << " " << b << std::endl;
    return 0;
}
