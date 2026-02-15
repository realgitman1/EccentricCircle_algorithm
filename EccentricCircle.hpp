#ifndef ECCENTRIC_CIRCLE_HPP
#define ECCENTRIC_CIRCLE_HPP

#include <vector>
#include <cmath>
#include <iostream>

class EccentricCircle {
private:
    float radius;
    float k_factor;
    std::vector<float> c_table;
    const int resolution = 360;

public:
    
	EccentricCircle(float r, float k) : radius(r), k_factor(k) {
        c_table.reserve(resolution);
        const float DEG_TO_RAD = 3.1415926535f / 180.0f;

        for (int i = 0; i < resolution; ++i) {
            float theta = static_cast<float>(i) * DEG_TO_RAD;
            
            float cos_t = std::cos(theta);
            float sin_t = std::sin(theta);
            float c = (k_factor * cos_t) + std::sqrt(1.0f - std::pow(k_factor * sin_t, 2));
            
            c_table.push_back(c);
        }
    }

    inline float get_boundary_distance(int degree) const {
      
	int index = (degree % resolution + resolution) % resolution;
        return radius * c_table[index];
    }

    
    float get_K_value() const {
        return 0.5f * (std::pow(k_factor, 2) / (1.0f - std::pow(k_factor, 2)));
    }
};

#endif
