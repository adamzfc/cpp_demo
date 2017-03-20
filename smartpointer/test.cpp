#include "smartpointer.h"

class SomeClass {
public:
    SomeClass() {
        std::cout << "SomeClass default constructor !" << std::endl;
    }
};

void testcast1() {
    SmartPointer<char> spunknown;
    SmartPointer<char> spnull = NULL;
    SmartPointer<SomeClass> spclass = new SomeClass;
//    SmartPointer<const char> spstr = "Hello world!";
}

int main() {
    testcast1();
    return 0;
}
