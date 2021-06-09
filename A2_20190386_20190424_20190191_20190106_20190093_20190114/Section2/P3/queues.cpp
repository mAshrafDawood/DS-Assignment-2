#include <iostream>

template <typename T> class DoubleLinkedList{
protected:
    class Node {
    public:
        T info;
        Node *next, *prev;
        Node(){next = prev = nullptr;}
        explicit Node(T elem){
            info = elem;
            next = prev = nullptr;
        }
    };

protected:
    Node *head, *tail;
    int length;
public:
    class iterator{
        friend class DoubleLinkedList<T>;
        Node* current;
    public:
        iterator(){
            current= nullptr;
        }
        void operator++(){
            if (current == nullptr) throw std :: runtime_error("Null pointer exception");
            if (current->next == nullptr) throw std :: runtime_error("You are already at the end of the list");
            current = current->next;
        }
        void operator--(){
            if (current == nullptr) throw std :: runtime_error("Null pointer exception");
            if (current->prev == nullptr) throw std :: runtime_error("You are already at the start of the list");
            current = current->prev;
        }
        T& operator*(){
            return current->info;
        }
        bool operator == (const iterator& itr){
            return current == itr.current;
        }
        bool operator != (const iterator& itr){
            return current != itr.current;
        }
    };
    DoubleLinkedList(){
        head = tail = nullptr;
        length = 0;
    }
    DoubleLinkedList(T val, int initSize){
        if (initSize <= 0) throw std :: runtime_error("Invalid number of nodes");
        int nodeCounter = initSize- 1;
        head = new Node(val);
        Node* temp = head;
        while (nodeCounter){
            nodeCounter--;
            temp->next = new Node(val);
            temp = temp->next;
        }
        tail = temp;
        length = initSize;
    }
    ~DoubleLinkedList() {
        emptyList();
    }
    void emptyList(){
        while (head != nullptr){
            Node* itr=head;
            head=head->next;
            delete itr;
        }
        length = 0;
    }

    int size(){
        return length;
    }
    void insert(T elem, iterator& pos){
        Node *toAdd = new Node(elem);

        if (pos.current == nullptr ){
            head = toAdd;
            pos.current = head;
        }
        else if(pos.current == head && length == 1){
            head->next = toAdd;
            tail = toAdd;
            tail->prev = head;
            pos.current = tail;
        }
        else if (pos.current == head){
            head->prev = toAdd;
            toAdd->next = head;
            head = toAdd;
        }
        else if (pos.current != head && pos.current != tail){
            pos.current->prev->next = toAdd;
            toAdd->prev = pos.current->prev;
            pos.current->prev = toAdd;
            toAdd->next = pos.current;
        } else{
            toAdd->next= nullptr;
            toAdd->prev=tail;
            tail->next=toAdd;
            tail=toAdd;
        }
        length++;
    }

    iterator erase(iterator pos){
        pos.current->prev->next = pos.current->next;
        pos.current->next->prev = pos.current->prev;
        Node* toDel = pos.current;
        pos.current = pos.current->next;
        if (pos.current == tail) throw std :: runtime_error("Unable to return out of bounds element");
        delete toDel;
        return pos;
    }

    DoubleLinkedList<T>& operator = (DoubleLinkedList<T> &anotherList){
        if (head != nullptr) emptyList();
        DoubleLinkedList<T>::iterator itr = anotherList.begin(), itr2 = this->begin();
        try{
            while(itr != anotherList.end()){
                this->insert(itr.current->info, itr2);
                ++itr;
            }
        }catch (...){}

        return *this;
    }

    iterator begin(){
        iterator itr;
        itr.current = head;
        return itr;
    }
    iterator end(){
        iterator itr;
        itr.current = nullptr;
        return itr;
    }
};
template <typename T>
class Queue: private DoubleLinkedList<T>{



public:
    Queue(): DoubleLinkedList<T>(){

    }
    Queue(T value , int initial_size): DoubleLinkedList<T>(value ,  initial_size){

    }
    ~Queue(){
      DoubleLinkedList<T>::emptyList();
    }
    T& front(){

       T& RTN = DoubleLinkedList<T>::head->info;
        return RTN;
    }

    void pop(){
        typename DoubleLinkedList< T>::iterator Itra = DoubleLinkedList<T>::begin();
      DoubleLinkedList<T> ::erase(Itra);
    }

    void push(T value) {
        if (size() > 0){


        typename DoubleLinkedList<T>::iterator it1 = DoubleLinkedList<T>::end();

        DoubleLinkedList<T>::insert(value, it1);}

    }
    int size(){
        return size();
    }

};

int main (){
    Queue <int> Q1;
   //std::cout<< Q1.size() ;
    Q1.push(5);
    Q1.push(6);
    Q1.push(7);
    Q1.push(8);
    Q1.push(6);
    Q1.push(10);
  //Q1.pop();
  //std::cout<<Q1.size()<<'\n';

std::cout<<Q1.front();
   // std::cout<<Q1.size();
}