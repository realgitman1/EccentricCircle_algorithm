#ifndef ECCENTRIC_HPP
#define ECCENTRIC_HPP

#include <array>
#include <cmath>

using namespace std;

class Eccentric{
private:
	float k = 0.0701;
	array<float, 512> c_table;

public:
	Eccentric(float r){

		const float STEP = (2.0f * 3.1415926535f) / 512;
		for(int i=0; i<512; i++){
			
			float theta = i * STEP;
			float cost_t = cos(theta);
			float sin_t = sin(theta);
			c_table[i] = r * (k * cos(theta) + sqrt(1.0f - (k*k*sin_t*sin_t)));
		
		}
	}

        float getTableValue(int index) const {
        	return c_table[index & 511];
	}
};
#endif
