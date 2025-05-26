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

    Number sumTwoNumbers(Number n1, Number n2) {
        Number n;
        n.sum(n1);
        n.sum(n2);
        return n;
    }
}  // namespace m_cpp_haptic
