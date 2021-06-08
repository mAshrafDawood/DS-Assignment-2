#ifndef P2_AVLTREE_H
#define P2_AVLTREE_H

#include <iostream>
#include <string>
using namespace std;

class AVLTree {
public:
    int value;
    AVLTree* left;
    AVLTree* right;

    AVLTree(int);
    ~AVLTree();
    static AVLTree* insertValue(AVLTree*, int);
    static AVLTree* deleteValue(AVLTree*, int);
    string displayInOrder();
    string displayPreOrder();
    string displayPostOrder();
private:
    int height;

    static AVLTree* rightRotation(AVLTree*);
    static AVLTree* leftRotation(AVLTree*);
    static AVLTree* getPredecessor(AVLTree*);
    static int getHeight(AVLTree*);
    static int getBalance(AVLTree*);
};

#endif //P2_AVLTREE_H