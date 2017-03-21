#ifndef SMARTPOINTER_H
#define SMARTPOINTER_H

#include <iostream>

template <typename T>
class SmartPointer {
public:
    SmartPointer():mPointer(NULL) {
        std::cout <<"create unkown smart pointer."<< std::endl;
    };
    SmartPointer(T *p):mPointer(p) {
        std::cout <<"create smart pointer at "<<static_cast<const void*>(p)<<std::endl;
    };
    ~SmartPointer(){
        std::cout << "release smart pointer at "<<static_cast<const void*>(mPointer)<<std::endl;
        if (mPointer) delete mPointer;
    };
    SmartPointer(const SmartPointer &other):mPointer(other.mPointer) {
        std::cout << "Copy smart pointer at " << static_cast<const void*>(other.mPointer) << std::endl;
    };
    SmartPointer &operator = (const SmartPointer &other) {
        if (this == &other) return *this;
        if (mPointer) delete mPointer;
        mPointer = other.mPointer;
        std::cout << "Assign smart pointer at " << static_cast<const void*>(other.mPointer) << std::endl;
        return *this;
    };
private:
    T *mPointer;
};

#endif
