#include <iostream>
#include <cstring>
using namespace std;

template <typename T>
class stack
{
private:
    int stack_size;
    T *myStack;
    int arraySize;

public:
    stack();
    stack(T value, int initial_size);
    T &top();
    void pop();
    void push(T value);
    int size();
    ~stack();
};
template <typename T>
stack<T>::stack()
{
    stack_size = 0;
    myStack = new T[1];
    arraySize = 1;
}
template <typename T>
stack<T>::stack(T value, int initial_size)
{

    arraySize = initial_size;
    myStack = new T[arraySize];
    stack_size = initial_size;
    for (int i = 0; i < stack_size; i++)
    {
        myStack[i] = value;
    }
}
template <typename T>
T &stack<T>::top()
{
    return myStack[stack_size - 1];
}
template <typename T>
void stack<T>::pop()
{
    stack_size--;
}
template <typename T>
void stack<T>::push(T value)
{
    stack_size++;
    if (stack_size > arraySize)
    {
        T *newArray = new T[arraySize * 2];
        for (int i = 0; i < arraySize; i++)
        {
            newArray[i] = myStack[i];
        }
        arraySize *= 2;
        delete[] myStack;
        myStack = newArray;
    }
    myStack[stack_size - 1] = value;
}
template <typename T>
int stack<T>::size()
{
    return stack_size;
}
template <typename T>
stack<T>::~stack()
{
    delete[] myStack;
}

int main()
{
    stack<int> ST;
    ST.push(50);
    ST.push(25);
    ST.push(30);
    cout << ST.top() << endl;

    stack<char> st1;
    string statement;
    cout << "Enter the expression u want to check" << endl;
    cin >> statement;
    bool comment = false;
    bool failed = false;
    for (int i = 0; i < statement.length(); i++)
    {
        if (comment)
        {
            if (statement.length() - i > 2)
            {
                if (statement[i] == '*' && statement[i + 1] == '/')
                {
                    comment = false;
                    st1.pop();
                    i++;
                }
            }
            continue;
        }
        if (statement[i] == '{' || statement[i] == '(' || statement[i] == '[')
        {
            st1.push(statement[i]);
            continue;
        }
        if (statement.length() - i > 2)
        {
            if (statement[i] == '/' && statement[i + 1] == '*')
            {
                st1.push(statement[i]);
                comment = true;
                continue;
            }
        }
        if (statement[i] == '}')
        {
            if (st1.top() == '{')
            {
                st1.pop();
                continue;
            }
            else
            {
                failed = true;
                break;
            }
        }
        else if (statement[i] == ')')
        {
            if (st1.top() == '(')
            {
                st1.pop();
            }
            else
            {
                failed = true;
                break;
            }
        }
        else if (statement[i] == ']')
        {
            if (st1.top() == '[')
            {
                st1.pop();
            }
            else
            {
                failed = true;
                break;
            }
        }
        else
        {
            failed = true;
            break;
        }
    }

    if (st1.size() == 0 && !failed)
    {
        cout << "Valid string" << endl;
    }
    else
    {
        cout << "Invalid string " << endl;
    }
    return 0;
}