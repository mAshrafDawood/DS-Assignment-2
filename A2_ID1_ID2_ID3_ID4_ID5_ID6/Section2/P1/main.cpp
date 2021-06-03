#include <iostream>
#include "DoubleLinkedList.hpp"

int main() {
    DoubleLinkedList<int> arr(1, 10);
    DoubleLinkedList<int>::iterator itr = arr.begin();
    std :: cout << *itr << std :: endl;
    arr.insert(1, itr);
    std :: cout << *itr << std :: endl;
    arr.insert(2, itr);
    std :: cout << *itr << std :: endl;
    arr.insert(3, itr);

    itr = arr.begin();
    while (!(itr == arr.end())){
        ++itr;

    }
    return 0;
}
