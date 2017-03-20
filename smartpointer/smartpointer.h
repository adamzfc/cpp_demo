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
private:
    T *mPointer;
};

#endif
