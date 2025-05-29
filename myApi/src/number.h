#ifndef NUMBER_H
#define NUMBER_H

#include "defines.h"
#include <vector>

namespace m_cpp_haptic {
    class DLL_API Number {
    private:
        float _x;

    public:
        std::vector<float> _vertices;
        Number();
        Number(float);
        void sum(Number n1);
        void print();
    };

    extern "C" {
    DLL_API Number* CreateNumber(float val);
    DLL_API void DestroyNumber(Number* number);
    DLL_API void Print(Number* number);

    DLL_API int InitData(Number* number, float* vertices, int length);
    DLL_API void UpdateData(Number* number);
    DLL_API float* GetData(Number* number, int* length);

    DLL_API void SumTwoNumbers(Number* r, Number* n1, Number* n2);
    DLL_API float Sum(float n1, float n2);
    }
}  // namespace m_cpp_haptic

#endif