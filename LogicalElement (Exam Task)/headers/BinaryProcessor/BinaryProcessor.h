#ifndef BINARYPROCESSOR_H_INCLUDED
#define BINARYPROCESSOR_H_INCLUDED

#include <vector>
using namespace std;

vector<int> convertToBinary(int num, int binaryLength);
vector<vector<int>> getBinariesTo(int iEnd);
long findMaxBinary(int length);
long binIntToDec(long number);
#endif // BINARYPROCESSOR_H_INCLUDED
