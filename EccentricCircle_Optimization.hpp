#ifndef ECCENTRIC_CIRCLE_HPP
#define ECCENTRIC_CIRCLE_HPP

#include <array>
#include <cmath>

class EccentricCircle {
private:
    float radius;

    static constexpr int RESOLUTION = 512; 
    static constexpr int MASK = RESOLUTION - 1;
    std::array<float, RESOLUTION> c_table;

public:
    EccentricCircle(float r, float k) : radius(r) {
        const float STEP = (2.0f * 3.1415926535f) / RESOLUTION;
        for (int i = 0; i < RESOLUTION; ++i) {
            float theta = i * STEP;
            float cos_t = std::cos(theta);
            float sin_t = std::sin(theta);
            
            c_table[i] = (k * cos_t) + std::sqrt(1.0f - (k * k * sin_t * sin_t));
        }
    }

    inline float get_dist_fast(int angle_index) const {
       
	return radius * c_table[angle_index & MASK];
    }
};

#endif
