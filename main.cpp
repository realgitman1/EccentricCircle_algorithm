#include "EccentricCircle.hpp"
#include <iostream>

int main() {

    float my_radius = 100.0f;
    float k_ideal = 0.707106f;
    
    EccentricCircle circle(my_radius, k_ideal);

    std::cout << "--- K-Library Initialization ---" << std::endl;
    std::cout << "Target K-Value: " << circle.get_K_value() << std::endl;
    std::cout << "Critical Point (k): " << k_ideal << std::endl;

    int current_angle = 45;
    
    float boundary_dist = circle.get_boundary_distance(current_angle);

    std::cout << "\n[Runtime Calculation]" << std::endl;
    std::cout << "Angle: " << current_angle << " deg" << std::endl;
    std::cout << "Pre-calculated Boundary Distance: " << boundary_dist << std::endl;

    float object_dist = 85.0f;
    if (object_dist < boundary_dist) {
        std::cout << "Result: COLLISION DETECTED!" << std::endl;
    } else {
        std::cout << "Result: CLEAR" << std::endl;
    }

    return 0;
}
