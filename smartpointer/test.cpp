#include "smartpointer.h"

class SomeClass {
public:
    SomeClass() {
        std::cout << "SomeClass default constructor !" << std::endl;
    }
};

void testcase1() {
    SmartPointer<char> spunknown;
    SmartPointer<char> spnull = NULL;
    SmartPointer<SomeClass> spclass = new SomeClass;
//    SmartPointer<const char> spstr = "Hello world!";
}

void testcase2() {
    SmartPointer<SomeClass> spclass1 = new SomeClass;
    std::cout << std::endl;
    spclass1 = spclass1;
    std::cout << std::endl;
    SmartPointer<SomeClass> spclassother = spclass1;
    std::cout << std::endl;
    SmartPointer<SomeClass> spclass2 = new SomeClass;
    std::cout << std::endl;
    spclass2 = spclass1;
    std::cout << std::endl;
}

int main() {
    testcase1();
    testcase2();
    return 0;
}
