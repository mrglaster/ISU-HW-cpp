#ifndef LINELISTELEM_H_INCLUDED
#define LINELISTELEM_H_INCLUDED


#include "LineList.h"

template <class T> class LineListElem {
    T data;
    LineListElem* next;
    public:
        LineListElem(const T& adata, LineListElem* anext);
        const T& getData() const;
        LineListElem* getNext();
        template<class X> friend class LineList;
};


template <class T> LineListElem<T>::LineListElem(const T& adata, LineListElem<T>* anext){
    data = adata;
    next = anext;
}

template <class T> LineListElem<T>* LineListElem<T>::getNext(){
    return next;
}

template <class T> const T& LineListElem<T>::getData() const{
    return data;
}


#endif // LINELISTELEM_H_INCLUDED
