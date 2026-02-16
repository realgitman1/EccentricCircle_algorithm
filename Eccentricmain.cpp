#include "Eccentric.hpp"
#include <iostream>

int main(int argc, char * argv[]){

	//example float r = first argument float;
	float r = stof(argv[1]);
	Eccentric eccentric(r);
	//example seta is second argument int;
	int index = stoi(argv[2]);

	float object_dist = eccentric.getTableValue(index);

	cout << "enermy status" <<  object_dist << endl;

	//example object_dist third argument float;
	float detect_dist = stof(argv[3]);

	if(detect_dist > object_dist){
		cout << "Collision detected" << endl;
	} else{
		cout << "clean" << endl;
	}

	return 0;
}
