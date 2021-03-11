//
// Created by Milosz Chojnacki on 11.03.2021.
//
#include "list.h"

template<class T>
List<T>::List() {
    std::cout << "it works!" << std::endl;
}

template class List<int>;
template class List<char>;
// Etc.. wszystkie typy jakich będziesz używac
