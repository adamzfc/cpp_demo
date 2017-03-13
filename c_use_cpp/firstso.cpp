#include <iostream>
#include "head.h"

A::A() {}
A::~A() {}
int A::gt()
{
    s = 10;
}
int A::pt()
{
    std::cout << s << std::endl;
}
