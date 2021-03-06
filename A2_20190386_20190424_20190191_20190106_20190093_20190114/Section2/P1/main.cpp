#include <iostream>
#include "DoubleLinkedList.hpp"
int main()
{
    DoubleLinkedList<int> arr1, arr2;
    DoubleLinkedList<int>::iterator it1 = arr1.begin();
    DoubleLinkedList<int>::iterator it2 = arr2.begin();
    arr1.insert(1, it1);
    arr1.insert(2, it1);
    arr1.insert(3, it1);
    arr1.insert(6, it1);
    arr1.insert(7, it1);
    arr1.insert(9, it1);
    arr1.insert(9, it1);
    arr1.insert(15, it1);
    arr1.insert(16, it1);

    std ::cout << "List 1--> ";

    DoubleLinkedList<int>::iterator itr = arr1.begin();
    while (itr != arr1.end())
    {
        std ::cout << *itr << " ";
        ++itr;
    }
    std ::cout << "\n\n";
    arr2.insert(2, it2);
    arr2.insert(5, it2);
    arr2.insert(6, it2);
    arr2.insert(8, it2);
    arr2.insert(12, it2);
    arr2.insert(18, it2);
    arr2.insert(20, it2);
    arr2.insert(25, it2);
    std ::cout << "List 2--> ";

    itr = arr2.begin();
    while (itr != arr2.end())
    {
        std ::cout << *itr << " ";
        ++itr;
    }
    std ::cout << "\n\n";

    DoubleLinkedList<int>::iterator it3 = arr1.begin();
    DoubleLinkedList<int>::iterator it4 = arr2.begin();
    DoubleLinkedList<int>::iterator it6 = arr1.end();
    DoubleLinkedList<int>::iterator it7 = arr2.end();
    arr1.merge(it3, it4, it6, it7);
    std ::cout << "After merge---> ";

    itr = arr1.begin();
    while (itr != arr1.end())
    {
        std ::cout << *itr << " ";
        ++itr;
    }
    std ::cout << "\n";

    return 0;
}
