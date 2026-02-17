:include "Eccentric.hpp"
#include <iostream>
#include <chrono>

using namespace std;

template <typename T>
inline void DoNotOptimize(T const& value) {
    asm volatile("" : : "r,m"(value) : "memory");
}

int main(int argc, char * argv[]){

	int iterations = 1000000;

	float r = 10.0f;
	
	Eccentric k_circle; 
	
	float x = 5.0f;
	float y = 5.0f;
			// 1. Standard Method (sqrt)
	auto start1 = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < iterations; ++i) {
		float res = std::sqrt(x * x + y * y)
		DoNotOptimize(res);
	}
        auto end1 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff1 = end1 - start1;
	
        // 2. K-Boundary Method (LUT)
        auto start2 = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < iterations; ++i) {
		float res2 = k_circle.getTableValue(i, r); 
		DoNotOptimize(res);
        }
        auto end2 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff2 = end2 - start2;

	std::cout << "Benchmark Results (" << iterations << " iterations):" << std::endl;
        std::cout << "Standard sqrt method: " << diff1.count() << "s" << std::endl;
        std::cout << "K-Boundary LUT method: " << diff2.count() << "s" << std::endl;
        std::cout << "Speedup: " << diff1.count() / diff2.count() << "x faster" << std::endl;

	return 0;
}

