//
// Created by Mohamed on 6/3/2021.
//

#ifndef P1_DOUBLELINKEDLIST_HPP
#define P1_DOUBLELINKEDLIST_HPP

template <typename T> class DoubleLinkedList{
private:
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
    }

    int size(){
        return length;
    }
    void insert(T elem, iterator pos){
        Node *toAdd = new Node(elem);

        if (pos.current == head){
            head->prev = toAdd;
            toAdd->next = head;
            head = toAdd;
        }
        else if (pos.current != nullptr){
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
    //not work
    iterator erase(iterator pos){
        pos.current->prev->next = pos.current->next;
        pos.current->next->prev = pos.current->prev;
        Node *toRtn = pos.current->next;
        if (pos.current == tail) throw std :: runtime_error("Unable to return out of bounds element");
        delete pos.current;
        return toRtn;
    }
    //To do
//    DoubleLinkedList<T>& operator = (const DoubleLinkedList<T> &anotherList){
//        if(head != nullptr){
//            emptyList();
//        }
//        if(anotherList.head== nullptr){
//            head= nullptr;
//            tail= nullptr;
//            length=0;
//        }
//        it2.current = anotherList.head->next;
//        head = anotherList.head;
//        Node* it1 = head;
//        while (it1 != nullptr){
//            it1->next = it2.current;
//            it2=it2.current->next;
//            it1 = it1->next;
//        }
//        tail=it1;
//    }
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

#endif //P1_DOUBLELINKEDLIST_HPP
