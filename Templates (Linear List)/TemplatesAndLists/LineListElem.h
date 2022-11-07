#ifndef LINELISTELEM_H_INCLUDED
#define LINELISTELEM_H_INCLUDED


#include "LineList.h"
#include <iostream>
using namespace std;


template <class T> class LinearListElement {
    T data;
    LinearListElement* next;
    public:
        LinearListElement(const T& adata, LinearListElement* anext);
        const T& getData() const;
        LinearListElement* getNext();
        template<class X> friend class LinearList;
        template<class X> friend ostream& operator <<(ostream& out, LinearListElement& list_elem);

};


template <class T> LinearListElement<T>::LinearListElement(const T& adata, LinearListElement<T>* anext){
    data = adata;
    next = anext;
}

template <class T> LinearListElement<T>* LinearListElement<T>::getNext(){
    return next;
}

template <class T> const T& LinearListElement<T>::getData() const{
    return data;
}

template <class T> ostream& operator <<(ostream& out, LinearListElement<T>& list_elem) {
    out<<list_elem->getData()<<' ';
}

#endif // LINELISTELEM_H_INCLUDED
