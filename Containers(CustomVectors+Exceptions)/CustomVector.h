#ifndef CUSTOMVECTOR_H_INCLUDED
#define CUSTOMVECTOR_H_INCLUDED

#define DEFAULT_CAPACITY  10
#define DEBUG 1

#include <iostream>>
using namespace std;


class CustomVectorException{};


class CustomVector{
    int* elements;
    int length, capacity;

    public:

        //Operators overload
        int& operator[](int index);
        CustomVector& operator =(const CustomVector& arr);

        friend ostream& operator <<(ostream& out, const CustomVector& arr);

        //Basic functions
        void increaseCapacity(int newCapacity);
        void insert(int element, int index);
        void append(int element);
        void remove(int index);
        int getSize() const;

        //Basic constructor
        explicit CustomVector(int startCapacity=DEFAULT_CAPACITY);

        //Constructor of copy
        CustomVector(const CustomVector& arr);

        //Destructor
        ~CustomVector();
};

void test_function();

#endif // CUSTOMVECTOR_H_INCLUDED
