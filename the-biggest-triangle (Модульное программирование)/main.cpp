#include <iostream>
#include <cstring>
#include <sys/stat.h>
//custom headers include
#include "geometry.h"
#include "file.h"
#include "search.h"

using namespace std;

//Constants
const int MAX_PATHLEN = 260;
const int MAX_TRIANGLES = 3;

//Function Prototypes
char* generate_ofilename(char* input_file);
void is_valid_file(char* input_file);


int main()
{
	cout << "Input filename: "<<endl;
	char* input_file = new char[MAX_PATHLEN];
	cin >> input_file;
	cout<<endl;
	char* output_file = generate_ofilename(input_file);
	int points_amount = countPoints(input_file);
	Point* arrPoints = new Point[points_amount];
	readPoints(input_file, arrPoints, points_amount);
	Triangle arrTriangles[MAX_TRIANGLES];
	searchLargestTriangles(arrPoints, points_amount, arrTriangles, MAX_TRIANGLES);
	if (!writeTriangles(output_file, arrTriangles, MAX_TRIANGLES))
	{
		cout << "Result writing error!" << endl;
		return -4;
	}
	cout << "Programm was succesfully executed!" << endl;

	delete[] arrPoints;
	delete[] input_file;
	delete[] output_file;
	return 0;
}




char* generate_ofilename(char* input_file){
    is_valid_file(input_file);
   char* prefix = "out_";
   int bufferSize = strlen(prefix) + strlen(input_file) + 1;
   char* concatString = new char[bufferSize];
   strcpy( concatString, prefix);
   strcat( concatString, input_file);
   cout<<"Potentialy, results You'll find  in: "<<concatString<<endl;
   return concatString;
}


void is_valid_file(char* filename){
    if(!(access(filename, F_OK )!= -1)){
        cout<<"Your experimental file doesn't exist!!!"<<endl;
        exit(-1);
    }
}
