#ifndef LINELIST_H_INCLUDED
#define LINELIST_H_INCLUDED

#include <iostream>
#include <ostream>
#include "LineListElem.h"
using namespace std;


/** Exception class */
class LineListException {};

/** Linear List Template */
template <class T> class LinearList
{

    LinearListElement<T>* start;
    LinearList(const LinearList& list);
    LinearList& operator =(const LinearList& list);
    int list_size = 0;

public:
    /** Constructor and destructor */
    LinearList();
    ~LinearList();

    /** Getting of first and latest element*/
    LinearListElement<T>* getStart();
    LinearListElement<T>* getLast();

    /**Manipulations with list's elements*/
    void deleteFirst();
    void deleteAfter(LinearListElement<T>* ptr);
    void insertFirst(const T& data);
    void append(const T& data);
    void insertAfter(LinearListElement<T>* ptr, const T& data);

    /** Operations with sizes */
    void increaseLenVal();
    void decreaseLenVal();
    int get_size();

    /**Operator(s) oveload*/
    template<class X> friend ostream& operator <<(ostream& out, LinearList& list);

};

/** Get first Element*/
template <class T> LinearListElement<T>* LinearList<T>::getStart()
{
    return start;
}

/**Get latest List's element. Works not effective*/
template <class T> LinearListElement<T>* LinearList<T>::getLast()
{
    LinearListElement<T>* current_item = start;
    LinearListElement<T>* previous_item = current_item;
    int cntr = 0;
    while(cntr < get_size())
    {
        cntr+=1;
        previous_item = current_item;
        current_item = current_item->next;
    }
    return previous_item;
}

/** Delete first list's element */
template<class T> void LinearList<T>::deleteFirst()
{
    if (start)
    {
        LinearListElement<T>* temp = start->next;
        delete start;
        start = temp;
    }
    else throw LineListException();
}

/** Increase List's size value*/
template <class T> void LinearList<T>::increaseLenVal()
{
    list_size++;
}

/** Decrease List's size value */
template <class T> void LinearList<T>::decreaseLenVal()
{
    list_size--;
}

/** Get size of the list */
template <class T> int LinearList<T>::get_size()
{
    return list_size;
}

/** Initialize Linear List*/
template <class T> LinearList<T>::LinearList()
{
    start = 0;
}

/** Destructor of the Linear List*/
template <class T> LinearList<T>::~LinearList()
{
    while (start)
    {
        deleteFirst();
        decreaseLenVal();
    }
}

/** Insert element to list's start*/
template <class T> void LinearList<T>::insertFirst(const T& data)
{
    LinearListElement<T>* second = start;
    start = new LinearListElement<T>(data, second);
    increaseLenVal();
}

/** Append element to list. NOT EFFECTIVE! */
template <class T> void LinearList<T>::append(const T& data)
{
    LinearListElement<T>* ptr = getLast();
    insertAfter(ptr, data);
}

/** Delete Element after another one */
template <class T> void LinearList<T>::deleteAfter(LinearListElement<T>* ptr)
{
    if (ptr && ptr->next)
    {
        LinearListElement<T>* temp = ptr->next;
        ptr->next = ptr->next->next;
        delete temp;
        decreaseLenVal();
    }
    else throw LineListException();
}

/** Insert element after another one */
template <class T> void LinearList<T>::insertAfter(LinearListElement<T>* ptr, const T& data)
{
    if (ptr)
    {
        LinearListElement<T>* temp = ptr->next;
        ptr->next = new LinearListElement<T>(data, temp);
        increaseLenVal();
    }
}

/** Output operator oveload*/
template <class T> ostream& operator <<(ostream& out, LinearList<T>& list)
{
    LinearListElement<T>* ptr = list.getStart();
    if (!ptr) out<<"EMPTY ";
    else while (ptr)
        {
            out<<ptr->getData()<<' ';
            ptr = ptr->getNext();
        }
    return out;
}


/** Functions testing some operations with Linear List*/
void test_linelist()
{
    LinearList<int> test_list;
    cout<<"Test Starts. List initialized: "<<test_list<<endl;
    test_list.insertFirst(10);
    cout<<"Step 1. Added 10: "<<test_list<<endl;
    cout<<"Length is: "<<test_list.get_size()<<endl<<endl;

    LinearListElement<int>* ptr = test_list.getStart();
    test_list.insertAfter(ptr, 15);
    cout<<"Step 2. Added 15: "<<test_list<<endl;
    cout<<"Length is: "<<test_list.get_size()<<endl<<endl;

    test_list.insertAfter(ptr->getNext(), 12);
    cout<<"Step 3. Added 12: "<<test_list<<endl;
    cout<<"Length is: "<<test_list.get_size()<<endl<<endl;

    test_list.insertFirst(7);
    cout<<"Inserted to start 7: "<<test_list<<endl;
    cout<<"Length is: "<<test_list.get_size()<<endl<<endl;

    test_list.append(42);
    cout<<"After true append "<<test_list<<endl;

}

#endif // LINELIST_H_INCLUDED
