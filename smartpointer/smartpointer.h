#ifndef SMARTPOINTER_H
#define SMARTPOINTER_H

#include <iostream>

#define COMPARE(_op_)                                \
bool operator _op_ (const SmartPointer& o) const {   \
    return mPointer _op_ o.mPointer;                 \
}                                                    \
bool operator _op_ (const T* o) const {              \
    return mPointer _op_ o;                          \
}                                                    \

template <typename T>
class SmartPointer {
public:
    SmartPointer():mPointer(NULL) {
        std::cout <<"create unkown smart pointer."<< std::endl;
    };
    SmartPointer(T *p):mPointer(p) {
        std::cout <<"create smart pointer at "<<static_cast<const void*>(p)<<std::endl;
        if (mPointer) mPointer->incRefCount();
    };
    ~SmartPointer(){
        std::cout << "release smart pointer at "<<static_cast<const void*>(mPointer)<<std::endl;
        if (mPointer && mPointer->decRefCount() == 0) delete mPointer;
    };
    SmartPointer(const SmartPointer &other):mPointer(other.mPointer) {
        std::cout << "Copy smart pointer at " << static_cast<const void*>(other.mPointer) << std::endl;
        if (mPointer) mPointer->incRefCount();
    };
    SmartPointer &operator = (const SmartPointer &other) {
        T *temp(other.mPointer);
        if (temp) temp->incRefCount();
        if (mPointer && mPointer->decRefCount() == 0) delete mPointer;
        mPointer = temp;
        return *this;
    };

    T& operator* () const { return *mPointer; };
    T* operator-> () const { return mPointer; };
    COMPARE(==);
    COMPARE(!=);
private:
    T *mPointer;
};

class RefBase {
public:
    RefBase() : mCount(0) {}
    void incRefCount() {
        mCount ++;
    }
    int decRefCount() {
        return --mCount;
    }
    int getRefCount() {
        return mCount;
    }
    virtual ~RefBase() {}
private:
    int mCount;
};

#endif
