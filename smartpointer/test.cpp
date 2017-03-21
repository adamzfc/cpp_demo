#include "smartpointer.h"

class SomeClass : public RefBase {
public:
    SomeClass() {
        std::cout << "SomeClass default constructor !" << std::endl;
    }
    ~SomeClass() {
        std::cout << "SomeClass deconstructor !" << std::endl;
    }
};

/*void testcase1() {
    SmartPointer<char> spunknown;
    SmartPointer<char> spnull = NULL;
    SmartPointer<SomeClass> spclass = new SomeClass;
//    SmartPointer<const char> spstr = "Hello world!";
}*/

/*void testcase2() {
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
}*/

void testcase3() {
    SomeClass *pSomeClass = new SomeClass();
    SmartPointer<SomeClass> spOuter = pSomeClass;
    std::cout << "SomeClass Ref Count (" << pSomeClass->getRefCount() << ") outer 1." << std::endl;
    {
        SmartPointer<SomeClass> spInner = spOuter;
        std::cout << "SomeClass Ref Count (" << pSomeClass->getRefCount() << ") inner." << std::endl;
    }
    std::cout << "SomeClass Ref Count (" << pSomeClass->getRefCount() << ") outer 2." << std::endl;
    std::cout << "new another SomeClass class for spOuter." << std::endl;
    SmartPointer<SomeClass> spOuter2 = new SomeClass();
    spOuter = spOuter2;
}

int main() {
//    testcase1();
//    testcase2();
    testcase3();
    return 0;
}
