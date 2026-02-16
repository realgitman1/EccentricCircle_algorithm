#include "Eccentric.hpp"
#include <iostream>

int main(int argc, char * argv[]){

	//example float r = 10f;
	float r = 10.0f;
	Eccentric eccentric(r);
	//example seta is 30 degree index is 21
	int index = 21;
	float object_dist = eccentric.getTableValue(index);

	cout << "enermy status" <<  object_dist << endl;

	//example object_dist = 5.0f
	float detect_dist = 5.0f;

	if(detect_dist > object_dist){
		cout << "Collision detected" << endl;
	} else{
		cout << "clean" << endl;
	}

	return 0;
}
