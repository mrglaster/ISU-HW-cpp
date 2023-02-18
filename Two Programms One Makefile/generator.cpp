#include <iostream>
#include <random>
#include <cmath>
#include <time.h>
#include <fstream>
#include <windows.h>

#define M_PI 3.14159265358979323846

/**Generates random radiam between -PI to PI*/
double generateRadian(){
	double radian = (double)((1 + (rand() % 100))) / 100.0 * M_PI;
	if (rand() % 2) radian *= -1;
	return radian;
}

/**Runs file processor*/
void runProcessor(){
	system("angle_processor.exe");
	system("pause");
}

/**Generates file with data*/
void generateFile(int linesCount){
	std::ofstream myfile;
	myfile.open ("output.txt");
	for (int i = 0; i < linesCount; i++){
		myfile << generateRadian() << " " <<generateRadian() << " " <<generateRadian() << " " <<std::endl;
	}
	runProcessor();
}

/**The main function*/
int main(int argc, char** argv){
	srand(time(NULL));
	int numbersToGenerate = std::stoi(argv[1]);
	if (numbersToGenerate <= 0) exit(-1);
	generateFile(numbersToGenerate);
}
