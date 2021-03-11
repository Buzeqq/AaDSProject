//
// Created by Miłosz Chojnacki on 11.03.2021.
//

#ifndef LABOR2_LIST_H
#define LABOR2_LIST_H
#include <iostream>

template<class T>
class List {
    T content;
    T* next;
public:
    List();

    void Print() const;

    int Length() const;

    bool Empty() const;

    T operator[] (int n) const;

    //TODO
    /*
    void Sort()
    */
    //~List();
};

#include "list.cpp"

#endif //LABOR2_LIST_H
