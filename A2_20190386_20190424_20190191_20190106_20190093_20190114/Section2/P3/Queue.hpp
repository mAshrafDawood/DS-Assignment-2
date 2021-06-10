//
// Created by Mohamed on 6/10/2021.
//

#ifndef QUEUE_USING_DLL_QUEUE_HPP
#define QUEUE_USING_DLL_QUEUE_HPP

#include "DoubleLinkedList.hpp"

template <typename T> class Queue{
    DoubleLinkedList<T> *arr;
public:

    Queue(){
        arr = new DoubleLinkedList<T>();
    }

    Queue(T value, int initSize){
        arr = new DoubleLinkedList<T>(value, initSize);
    }

    ~Queue(){
        arr->emptyList();
        delete arr;
    }

    T& front(){
        return *arr->begin();
    }

    void pop(){
        typename DoubleLinkedList<T>::iterator itr = arr->begin();
        arr->erase(itr);
    }

    void push(T value){
        typename DoubleLinkedList<T>::iterator itr = arr->end();
        arr->insert(value, itr);
    }

    int size(){
        return arr->size();
    }

};

#endif //QUEUE_USING_DLL_QUEUE_HPP
