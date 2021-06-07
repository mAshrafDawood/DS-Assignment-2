#include <iostream>
#include "DoubleLinkedList.hpp"

int main() {

    DoubleLinkedList<int> arr1;
    DoubleLinkedList<int>::iterator it1 = arr1.begin();
    arr1.insert(1, it1);
    arr1.insert(2, it1);
    arr1.insert(3, it1);
    arr1.insert(4, it1);
    arr1.insert(5, it1);

    std :: cout << "List --> ";
    try{
        DoubleLinkedList<int>::iterator itr = arr1.begin();
        while (true){
            std :: cout << *itr << " ";
            ++itr;
        }
    }catch (...){
        std :: cout << "\n\n";
    }

    it1 = arr1.begin();
    ++it1;

    std :: cout << "Element to delete : " << *it1 << "\n";

    arr1.erase(it1);

    std :: cout << "List --> ";
    try{
        DoubleLinkedList<int>::iterator itr = arr1.begin();
        while (true){
            std :: cout << *itr << " ";
            ++itr;
        }
    }catch (...){
        std :: cout << "\n\n";
    }

    return 0;
}
