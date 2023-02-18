#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>

/**Checks if file exists*/
inline bool fileExists (const std::string& name) {
    std::ifstream f(name.c_str());
    return f.good();
}

/**Converts bunch of radians into the angle*/
double getAngle(double x, double y, double z){
	return 2 * sin(x) * sin(y) + cos(z);
}

/**Reads bunch of radians from the file and converts'em to degree*/
void processFile(){
	std::ifstream infile("output.txt");
	std::string line;
	int currentPos = 1;
	std::cout<<std::endl<<"Generated Angles (In Radians)"<<std::endl;
	while (std::getline(infile, line)){
		std::istringstream iss(line);
		double x, y, z;
		char separator;
		if (!(iss >> x >> separator >> y >> separator >> z)) { break; } // error
		iss >> x >> separator >> y >> separator >> z;
		std::cout<<currentPos<<") "<<getAngle(x, y, z)<<std::endl;
	}
	std::cout<<std::endl;
}

/**The current main function*/
int main(){
	if (!fileExists("output.txt")) {
		std::cout<<"Error! File output.txt doesn't exist!"<<std::endl;
		exit(-1);
	}
	processFile();
}