#include "Queue.hpp"
#include <iostream>

int main()
{
    Stack St1;
    St1.push(5);
    St1.push(10);
    St1.push(11);
    St1.push(20);
    std::cout << St1.top() << " ";
    St1.pop();
    std::cout << St1.top();
}
