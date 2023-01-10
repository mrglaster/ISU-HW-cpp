#include <vector>
#include <cmath>
#include "../../headers/BinaryProcessor/BinaryProcessor.h"
using namespace std;

/**Converts the integer number to binary radix and transforms it into vector*/
vector<int> convertToBinary(int num, int binaryLength){
    vector<int> bits(binaryLength, 0);
    if (num == 0) return bits;
    int i = binaryLength - 1;
    while (num != 0) {
		bits[i--] = (num % 2);
		num = num / 2;
    }
    return bits;
}

/**Returns array of binary vectors in range 0 to iEnd*/
vector<vector<int>> getBinariesTo (int iEnd){
    int n = (int)ceil(log(iEnd+1) / log (2));
    vector<vector<int> > binary_nos;
    for (int i = 0; i <= iEnd; i++) {
		vector<int> bits =
			convertToBinary(i, n);
		binary_nos.push_back(bits);
	}
	return binary_nos;
}

/**Returns maximal binary number for current length*/
long findMaxBinary(int length){
    if (length == 0) return 0;
    if (length == 1) return 1;
    int number = 1;
    for (int i = 0; i < length -1; i++ ){
        number = number * 10 +1;
    }
    return number;
}

/**Converts binary number to integer*/
long binIntToDec(long number){
     int dec = 0, i = 0, rem;
     while (number!=0) {
        rem = number % 10;
        number /= 10;
        dec += rem * pow(2, i);
        ++i;
    }
}
