#include <iostream>
#include "CustomVector.h"
using namespace std;


//Constructor
CustomVector::CustomVector(int startCapacity) {
    if (startCapacity <= 0){
        capacity = DEFAULT_CAPACITY;
        if(DEBUG) cout<<"Troubles during CustomVector creation! Excepted length >0; We set the capacity to "<<DEFAULT_CAPACITY<<endl;
    }
    else capacity = startCapacity;
    elements = new int[capacity];
    length = 0;
}

//Constructor of copy
CustomVector::CustomVector(const CustomVector &arr) {
    elements = new int[arr.capacity];
    length = arr.length;
    capacity = arr.capacity;
    for (int i=0; i<length; i++) elements[i]=arr.elements[i];
}


//Destructor
CustomVector::~CustomVector(){
    delete[] elements;
}

//Overload of operator =
CustomVector& CustomVector::operator =(const CustomVector& arr) {
    if (this==&arr) return *this;
    if (capacity != arr.capacity){
        delete[] elements;
        elements = new int[arr.capacity];
        capacity = arr.capacity;
    }
    length = arr.length;
    for (int i=0; i<length; i++)
        elements[i] = arr.elements[i];
    return *this;
}

//Overload of operator []
int& CustomVector::operator [](int index)  {
   if (index >= length || index < 0) throw CustomVectorException();
   else return elements[index];
}


//Insert element by id
void CustomVector::insert(int element, int index) {
      if (index < 0 || index > length) throw CustomVectorException();
      if (length==capacity) increaseCapacity(length+1);
      for (int j=length-1; j>=index; j--) elements[j+1]=elements[j];
      length++;
      elements[index]=element;
}

//Append element to the end of the CustomVector
void CustomVector::append(int element){
    insert(element, length);
}

//Remove element by index
void CustomVector::remove(int index) {
    if (index < 0 || index >= length)  throw CustomVectorException();
    for (int j=index; j<length-1; j++)
      elements[j] = elements[j+1];
    elements[length-1]=0;
    length--;
}

// Increace capacity
void CustomVector::increaseCapacity(int newCapacity){
   capacity = newCapacity < capacity*2 ? capacity*2 : newCapacity;
   int* newPtr = new int[capacity];
   for (int i=0; i<length; i++) newPtr[i]=elements[i];
   delete[] elements;
   elements = newPtr;
}

//Get CustomVector's length
int CustomVector::getSize() const{
    return length;
}

//Output operator overlaod
ostream& operator <<(ostream& out, const CustomVector& arr) {
   out<<"Total size: "<<arr.length<<endl;
   for (int i=0; i<arr.length; i++) out<<arr.elements[i]<<endl;
   return out;
}

void test_function(){
   CustomVector arr(4);

   // Some tests
   for (int i=0; i<4; i++)
     arr.append(i+1);
   cout<<arr<<endl;

    for (int i=0; i<8; i+=2)
        arr.insert(10+i,i);
    cout<<arr<<endl;

    for (int i=1; i<8; i+=2)
      arr[i]=20+i;
   cout<<arr<<endl;

    for (int i=6; i>=0; i-=3)
        arr.remove(i);
    cout<<arr<<endl;
}

