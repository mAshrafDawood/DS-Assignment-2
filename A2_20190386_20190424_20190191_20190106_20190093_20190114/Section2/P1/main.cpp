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
    arr1.insert(15, it1);
    arr1.insert(16, it1);

    std ::cout << "List 1--> ";
    try
    {
        DoubleLinkedList<int>::iterator itr = arr1.begin();
        while (true)
        {
            std ::cout << *itr << " ";
            ++itr;
        }
    }
    catch (...)
    {
        std ::cout << "\n\n";
    }
    arr2.insert(2, it2);
    arr2.insert(5, it2);
    arr2.insert(6, it2);
    arr2.insert(8, it2);
    arr2.insert(12, it2);
    std ::cout << "List 2--> ";
    try
    {
        DoubleLinkedList<int>::iterator itr = arr2.begin();
        while (true)
        {
            std ::cout << *itr << " ";
            ++itr;
        }
    }
    catch (...)
    {
        std ::cout << "\n\n";
    }
    DoubleLinkedList<int>::iterator it3 = arr1.begin();
    DoubleLinkedList<int>::iterator it4 = arr2.begin();
    arr1.merge(it3, it4);
    std ::cout << "After merge---> ";
    try
    {
        DoubleLinkedList<int>::iterator itr = arr1.begin();
        while (true)
        {
            std ::cout << *itr << " ";
            ++itr;
        }
    }
    catch (...)
    {
        std ::cout << "\n";
    }

    return 0;
}
