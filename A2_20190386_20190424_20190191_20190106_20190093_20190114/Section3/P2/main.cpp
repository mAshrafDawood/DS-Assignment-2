#include <iostream>
#include "AVLTree.h"

using namespace std;

int main() {
	AVLTree* root = new AVLTree(14);

	root = AVLTree::insertValue(root, 17);
	root = AVLTree::insertValue(root, 11);
	root = AVLTree::insertValue(root, 7);
	root = AVLTree::insertValue(root, 53);
	root = AVLTree::insertValue(root, 4);
	root = AVLTree::insertValue(root, 13);

	cout << "Insert 14, 17, 11, 7, 53, 4, 13 into an empty AVL tree \n";
	cout << root->displayInOrder();
	cout << "\n";

	root = AVLTree::insertValue(root, 12);
	cout << "Now insert 12 \n";
	cout << root->displayInOrder();
	cout << "\n";

	root = AVLTree::insertValue(root, 8);
	cout << "Now insert 8 \n";
	cout << root->displayInOrder();
	cout << "\n";

	root = AVLTree::deleteValue(root, 53);
	cout << "Now remove 53 \n";
	cout << root->displayInOrder();
	cout << "\n";

	root = AVLTree::deleteValue(root, 11);
	cout << "Now remove 11 \n";
	cout << root->displayInOrder();
	cout << "\n";

	root = AVLTree::deleteValue(root, 8);
	cout << "Now remove 8 \n";
	cout << root->displayInOrder();
	cout << "\n";
}