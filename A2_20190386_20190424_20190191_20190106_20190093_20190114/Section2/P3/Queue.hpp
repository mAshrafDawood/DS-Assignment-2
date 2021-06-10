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
class Stack{
    Queue <int> *stack;

public:
    Stack(){
        stack = new Queue<int>();
    }
    int& top(){
        return stack->front();
    }
    void pop(){

        stack->pop();
    }
    void push(int value){

        DoubleLinkedList <int> list1 ;

        DoubleLinkedList <int> ::iterator it1 = list1.end();
        list1.insert(value,it1);
        while (stack->size()) {
            list1.insert(stack->front(), it1);
            stack->pop();
        }
        for(it1=list1.begin();it1!=list1.end();++it1){
            stack->push(*it1);
        }

    }


};

#endif //QUEUE_USING_DLL_QUEUE_HPP
