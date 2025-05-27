#include "number.h"
#include <iostream>
using namespace m_cpp_haptic;

int main() {

    Number x = 5.;
    Number y = 7.;

    Number z;
    SumTwoNumbers(&z, &x, &y); // x + y
    z.print();

    float w = Sum(4.f, 6.f);
    std::cout<< "[c++] Sum(float, float): " << w << std::endl;
    
    return 0;
}
