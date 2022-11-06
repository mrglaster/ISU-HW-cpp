#ifndef LINELIST_H_INCLUDED
#define LINELIST_H_INCLUDED

#include <iostream>
#include <ostream>
#include "LineListElem.h"
using namespace std;

class LineListException{};

template <class T> class LineList {

   LineListElem<T>* start;
   LineList(const LineList& list);
   LineList& operator =(const LineList& list);
   int list_size = 0;
   public:
        LineList();
        ~LineList();
        LineListElem<T>* getStart();
        void deleteFirst();
        void deleteAfter(LineListElem<T>* ptr);
        void insertFirst(const T& data);
        void insertAfter(LineListElem<T>* ptr, const T& data);
        void increaseLenVal();
        void decreaseLenVal();

        int get_size();

        template<class X> friend ostream& operator <<(ostream& out, LineList& list);
};

template <class T> LineListElem<T>* LineList<T>::getStart(){
    return start;
}

template <class T> void LineList<T>::deleteFirst() {
        if (start){
            LineListElem<T>* temp = start->next;
            delete start;
            start = temp;
        }
    else throw LineListException();
}


template <class T> void LineList<T>::increaseLenVal(){
    list_size++;
}

template <class T> void LineList<T>::decreaseLenVal(){
    list_size--;
}


template <class T> int LineList<T>::get_size(){
    return list_size;
}

template <class T> LineList<T>::LineList() {
    start = 0;
}

template <class T> LineList<T>::~LineList(){
    while (start){
        deleteFirst();
        decreaseLenVal();
    }
}


template <class T> void LineList<T>::insertFirst(const T& data){
   LineListElem<T>* second = start;
   start = new LineListElem<T>(data, second);
   increaseLenVal();
}

template <class T> void LineList<T>::deleteAfter(LineListElem<T>* ptr){
      if (ptr && ptr->next) {
            LineListElem<T>* temp = ptr->next;
            ptr->next = ptr->next->next;
            delete temp;
            decreaseLenVal();
      } else throw LineListException();
}

template <class T> void LineList<T>::insertAfter(LineListElem<T>* ptr, const T& data){
    if (ptr){
        LineListElem<T>* temp = ptr->next;
        ptr->next = new LineListElem<T>(data, temp);
        increaseLenVal();
    }
}

template <class T> ostream& operator <<(ostream& out, LineList<T>& list) {
    LineListElem<T>* ptr = list.getStart();
    if (!ptr) out<<"EMPTY ";
    else while (ptr){
      out<<ptr->getData()<<' ';
      ptr = ptr->getNext();
    }
    return out;
}


void test_linelist(){
    LineList<int> test_list;
    cout<<"Test Starts. List initialized: "<<test_list<<endl;
    test_list.insertFirst(10);
    cout<<"Step 1. Added 10: "<<test_list<<endl;
    cout<<"Length is: "<<test_list.get_size()<<endl<<endl;

    LineListElem<int>* ptr = test_list.getStart();
    test_list.insertAfter(ptr, 15);
    cout<<"Step 2. Added 15: "<<test_list<<endl;
    cout<<"Length is: "<<test_list.get_size()<<endl<<endl;

    test_list.insertAfter(ptr->getNext(), 12);
    cout<<"Step 3. Added 12: "<<test_list<<endl;
    cout<<"Length is: "<<test_list.get_size()<<endl<<endl;

    test_list.insertFirst(7);
    cout<<"Inserted to start 7: "<<test_list<<endl;
    cout<<"Length is: "<<test_list.get_size()<<endl<<endl;
}

#endif // LINELIST_H_INCLUDED
