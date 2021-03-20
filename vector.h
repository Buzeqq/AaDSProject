//
// Created by Milosz Chojnacki on 18.03.2021.
//

#ifndef LABOR2_VECTOR_H
#define LABOR2_VECTOR_H

#include <iostream>
#include <cstring>

template <class T>
class Vector {
    int allocatedSize;
    int count;
    T* root;

public:

    Vector() {
        allocatedSize = 1;
        count = 0;
        root = new T[allocatedSize];
    }

    void Reallocate(int reallocateSize) {
        allocatedSize = reallocateSize;
        T* newRoot = new T[allocatedSize];
        memcpy(newRoot, root, count*sizeof(T));
        delete[] root;
        root = newRoot;
    }

    void push_back(T newElement) {
        if (count == allocatedSize) Reallocate(2 * allocatedSize);
        root[count] = newElement;
        count++;
    }

    void Print() {
        for (int i = 0; i < count; i++) {
            std::cout << root[i] << " ";
        }
    }
};

#endif //LABOR2_VECTOR_H
