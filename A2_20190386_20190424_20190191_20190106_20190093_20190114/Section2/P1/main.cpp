#include <iostream>
#include "DoubleLinkedList.hpp"

int main() {
    DoubleLinkedList<int> arr(1, 1);
    DoubleLinkedList<int>::iterator itr = arr.begin();
    std :: cout << *itr << std :: endl;
    arr.insert(7, itr);
    std :: cout << *itr << std :: endl;
    arr.insert(2, itr);
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
