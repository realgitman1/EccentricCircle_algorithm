#include "EccentricCircle_Optimization.hpp"
#include <iostream>
#include <chrono>
#include <cmath>
#include <vector>

void run_benchmark() {
    const int iterations = 10000000;
    float r = 100.0f;
    float k = 0.7071f;
    float x = 50.0f, y = 50.0f;

    EccentricCircle k_circle(r, k);

    // 1. Standard Method (sqrt)
    auto start1 = std::chrono::high_resolution_clock::now();
    volatile float dummy1;
    for (int i = 0; i < iterations; ++i) {
        dummy1 = std::sqrt(x * x + y * y);
    }
    auto end1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff1 = end1 - start1;

    // 2. K-Boundary Method (LUT)
    auto start2 = std::chrono::high_resolution_clock::now();
    volatile float dummy2;
    for (int i = 0; i < iterations; ++i) {
        
        dummy2 = k_circle.get_dist_fast(i); 
    }
    auto end2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff2 = end2 - start2;

    std::cout << "Benchmark Results (" << iterations << " iterations):" << std::endl;
    std::cout << "Standard sqrt method: " << diff1.count() << "s" << std::endl;
    std::cout << "K-Boundary LUT method: " << diff2.count() << "s" << std::endl;
    std::cout << "Speedup: " << diff1.count() / diff2.count() << "x faster" << std::endl;
}

int main() {
    run_benchmark();
    return 0;
}
