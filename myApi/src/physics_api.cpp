#include "physics_api.h"
#include <iostream>

namespace m_physics_lib {
    PhysicsApi::PhysicsApi() : _time(0), _timestep(0.01) {
    }

    PhysicsApi::PhysicsApi(float timestep) : _time(0), _timestep(timestep) {
    }

    void PhysicsApi::initModel(float* vertices, int length) {
        int size = length * sizeof(float);
        _vertices0.resize(length);
        _vertices.resize(length);
        memcpy(_vertices0.data(), vertices, size);
        memcpy(_vertices.data(), vertices, size);
    }

    float* PhysicsApi::getModel() {
        return _vertices.data();
    }

    void PhysicsApi::simpleAnimation(float velocity, float period) {

        // simple function to animate on the y axis

        for (int i = 0; i < _vertices0.size(); i += 3) {
            auto offset = sin(getTime() * velocity + _vertices0[i]*period)*0.2f;
            _vertices[i + 1] = _vertices0[i + 1] + offset;
        }
        nextTime();
    }

    void PhysicsApi::nextTime() {
        _time += _timestep;
    }

    float PhysicsApi::getTime() {
        return _time;
    }

    PhysicsApi* CreateInstance(float timestep) {
        return new PhysicsApi(timestep);
    }

    void DestroyInstance(PhysicsApi* instance) {
        delete instance;
    }

    int InitData(PhysicsApi* instance, float* vertices, int length) {
        int size = length * sizeof(float);
        instance->initModel(vertices, length);
        return size;
    }

    void UpdateData(PhysicsApi* instance, float velocity, float period) {
        instance->simpleAnimation(velocity, period);
    }

    float* GetData(PhysicsApi* instance) {
        return instance->getModel();
    }

}  // namespace m_physics_lib
