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
        Node* current;
    public:
        void operator++(){
            if (current == tail) throw std::runtime_error("You are already at the end of the list");
            current = current->next;
        }
        void operator--(){
            if (current == this->head) throw std :: runtime_error("You are already at the start of the list");
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
        tail->next = new Node();
        length = initSize;
    }
    ~DoubleLinkedList(){
        emptyList();
    }
    void emptyList(){
        Node *itr = head;
        while (itr != tail->next){
            Node *toDel = itr;
            itr = itr->next;
            delete toDel;
        }
    }
    int size(){
        return length;
    }
    void insert(T elem, iterator pos){
        Node *toAdd = new Node(elem);

        toAdd->next = pos.current;
        pos.current->prev = toAdd;

        if (pos.current->prev != nullptr){
            pos.current->prev->next = toAdd;
            toAdd->prev = pos.current->prev;
        }
    }
    iterator erase(iterator pos){
        pos.current->prev->next = pos.current->next;
        pos.current->next->prev = pos.current->prev;
        Node *toRtn = pos.current->next;
        if (pos.current == tail) throw std :: runtime_error("Unable to return out of bounds element");
        delete pos.current;
        return toRtn;
    }
    DoubleLinkedList<T>& operator = (const DoubleLinkedList<T> anotherList){
        emptyList();
        iterator it2;
        it2.current = anotherList.head->next;
        head = anotherList.head;
        Node* it1 = head;
        while (it2 != anotherList.tail->next){
            it1->next = it2.current;
            it2++;
            it1 = it1->next;
        }
    }
    iterator begin(){
        iterator itr;
        itr.current = head;
        return itr;
    }
    iterator end(){
        iterator itr;
        itr.current = tail->next;
        return itr;
    }
};

#endif //P1_DOUBLELINKEDLIST_HPP
