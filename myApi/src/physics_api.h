#ifndef PHYSICS_API_H
#define PHYSICS_API_H

#include "defines.h"
#include <vector>

namespace m_physics_lib {
    class DLL_API PhysicsApi {
    private:
        float _timestep;
        float _time;

        // TODO: create a class to represent the models
        std::vector<float> _vertices0;
        std::vector<float> _vertices;

    public:
        PhysicsApi();
        PhysicsApi(float times_step);
        void initModel(float* vertices, int length);
        float* getModel();
        void simpleAnimation(float velocity, float period);
        inline void nextTime();
        inline float getTime();
    };

    extern "C" {
    DLL_API PhysicsApi* CreateInstance(float timestep);
    DLL_API void DestroyInstance(PhysicsApi* number);

    DLL_API int InitData(PhysicsApi* number, float* vertices, int length);
    DLL_API void UpdateData(PhysicsApi* number, float velocity, float period);
    DLL_API float* GetData(PhysicsApi* number);
    }
}  // namespace m_physics_lib

#endif