#include "AVLTree.h"

AVLTree::AVLTree(int _value)
{
	value = _value;
	left = NULL;
	right = NULL;
	height = 1;
}

AVLTree::~AVLTree()
{
	if (left != NULL)
	{
		delete left;
	}

	if (right != NULL)
	{
		delete right;
	}
}

AVLTree *AVLTree::insertValue(AVLTree *node, int newValue)
{
	if (newValue < node->value)
	{
		if (node->left != NULL)
			node->left = insertValue(node->left, newValue);
		else
			node->left = new AVLTree(newValue);
	}
	else if (newValue > node->value)
	{
		if (node->right != NULL)
			node->right = insertValue(node->right, newValue);
		else
			node->right = new AVLTree(newValue);
	}

	node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
	int balance = getBalance(node);

	if (balance > 1 && newValue < node->left->value)
	{ // Left Left
		return rightRotation(node);
	}
	else if (balance < -1 && newValue > node->right->value)
	{ // Right Right
		return leftRotation(node);
	}
	else if (balance > 1 && newValue > node->left->value)
	{ // Left Right
		node->left = leftRotation(node->left);
		return rightRotation(node);
	}
	else if (balance < -1 && newValue < node->right->value)
	{ // Right Left
		node->right = rightRotation(node->right);
		return leftRotation(node);
	}

	return node;
}

AVLTree *AVLTree::deleteValue(AVLTree *node, int newValue)
{
	if (newValue < node->value)
		node->left = deleteValue(node->left, newValue);
	else if (newValue > node->value)
		node->right = deleteValue(node->right, newValue);
	else
	{
		if (node->left == NULL || node->right == NULL)
		{
			AVLTree *temp = NULL;
			if (node->left != NULL)
				temp = node->left;
			else
				temp = node->right;

			if (temp == NULL)
			{ // Has no children
				temp = node;
				node = NULL;
			}
			else
			{ // Has one child
				*node = *temp;
			}

			delete temp;
		}
		else
		{
			AVLTree *temp = getPredecessor(node->right);
			node->value = temp->value;
			node->right = deleteValue(node->right, temp->value);
		}
	}

	if (node == NULL)
		return NULL;

	node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
	int balance = getBalance(node);

	if (balance > 1 && getBalance(node->left) >= 0)
	{ // Left Left
		return rightRotation(node);
	}
	else if (balance < -1 && getBalance(node->right) <= 0)
	{ // Right Right
		return leftRotation(node);
	}
	else if (balance > 1 && getBalance(node->left) < 0)
	{ // Left Right
		node->left = leftRotation(node->left);
		return rightRotation(node);
	}
	else if (balance < -1 && getBalance(node->right) > 0)
	{ // Right Left
		node->right = rightRotation(node->right);
		return leftRotation(node);
	}

	return node;
}

AVLTree *AVLTree::rightRotation(AVLTree *node)
{
	AVLTree *x = node->left;
	AVLTree *y = x->right;

	x->right = node;
	node->left = y;

	node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
	x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

	return x;
}

AVLTree *AVLTree::leftRotation(AVLTree *node)
{
	AVLTree *x = node->right;
	AVLTree *y = x->left;

	x->left = node;
	node->right = y;

	node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
	x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

	return x;
}

AVLTree *AVLTree::getPredecessor(AVLTree *node)
{
	AVLTree *result = node;

	while (result->left != NULL)
		result = result->left;

	return result;
}

int AVLTree::getHeight(AVLTree *node)
{
	if (node == NULL)
		return 0;
	else
		return node->height;
}

int AVLTree::getBalance(AVLTree *node)
{
	if (node == NULL)
		return 0;
	else
		return getHeight(node->left) - getHeight(node->right);
}

string AVLTree::displayInOrder()
{
	string result = "";
	if (left != NULL)
		result += left->displayInOrder();
	result += to_string(value) + " ";
	if (right != NULL)
		result += right->displayInOrder();
	return result;
}

string AVLTree::displayPreOrder()
{
	string result = "";
	if (left != NULL)
		result += left->displayPreOrder();
	if (right != NULL)
		result += right->displayPreOrder();
	result += to_string(value) + " ";
	return result;
}

string AVLTree::displayPostOrder()
{
	string result = "";
	result += to_string(value) + " ";
	if (left != NULL)
		result += left->displayPostOrder();
	if (right != NULL)
		result += right->displayPostOrder();
	return result;
}