#include "number.h"
#include <iostream>

namespace m_cpp_haptic {
    Number::Number() : _x(0.f) {
    }

    Number::Number(float x) : _x(x) {
    }

    void Number::sum(Number n1) {
        _x += n1._x;
    }

    void Number::print() {
        std::cout << "val: " << _x << std::endl;
    }

    Number* CreateNumber(float val) {
        return new Number(val);
    }

    void DestroyNumber(Number* number) {
        delete number;
    }

     void Print(Number* number) {
        number->print();
    }

    void SumTwoNumbers(Number* r, Number* n1, Number* n2) {
        r->sum(*n1);
        r->sum(*n2);
    }

    float Sum(float n1, float n2) {
        return n1 + n2;
    }
}  // namespace m_cpp_haptic
