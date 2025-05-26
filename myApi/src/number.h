#ifndef NUMBER_H
#define NUMBER_H

#include "defines.h"

namespace m_cpp_haptic {
    class DLL_API Number {
    private:
        float _x;

    public:
        Number();
        Number(float);
        void sum(Number n1);
        void print();
    };

    DLL_API Number sumTwoNumbers(Number n1, Number n2);

}  // namespace m_cpp_haptic
#endif