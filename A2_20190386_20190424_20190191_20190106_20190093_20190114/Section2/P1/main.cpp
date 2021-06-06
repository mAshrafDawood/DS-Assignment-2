#include <iostream>
#include "DoubleLinkedList.hpp"

int main() {

    DoubleLinkedList<int> arr(1, 1);
    DoubleLinkedList<int>::iterator itr = arr.begin();
    DoubleLinkedList<int>::iterator it2=arr.end();
    DoubleLinkedList<int>arr2(4,4);
    ///arr=arr2;
    std :: cout << *itr << std :: endl;
    arr.insert(7, itr);
    std :: cout << *itr << std :: endl;
    arr.insert(2, it2);
    std :: cout << *itr << std :: endl;
    arr.insert(3, itr);
    itr = arr.begin();
    while (true){
        try{
            std :: cout << *itr << " ";
            ++itr;
        }
        catch (std :: runtime_error& e){
            std :: cout << e.what();
            break;
        }
    }
    return 0;
}
