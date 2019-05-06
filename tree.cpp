#include "tree.h"


tree::tree()
{
	root = nullptr;
	size = 0;
	height = 0;
}

tree::~tree()
{
	if (root!= nullptr)
		clear(root);
}

Node* tree::getRoot()
{
	return root;
}

int tree::getHeight()
{
	return height;
}

string tree::getEntry(int id)
{
	Node *temp = findNode(id, root);
	return temp->data;
}

bool tree::contains(int id)
{
	Node* target = findNode(id, root);

	if (target == nullptr)
		return false;
	return true;
}

bool tree::clear(Node* current)
{


	if (current->left != nullptr)
	{
		clear(current->left);
	}

	
	if (current->right != nullptr)
	{
		clear(current->right);
	}

	delete current;
	size--;

	if (size == 0)
		return true;
	return false;
}

void tree::postorderTraverse(Node* current)
{



	if (current->left != nullptr)
	{
		postorderTraverse(current->left);
	}

	cout << current->id << "\n" << current->data << "\n\n";

	if (current->right != nullptr)
	{
		postorderTraverse(current->right);
	}

}

void tree::inorderTraverse(Node* current)
{

	

	if (current->left != nullptr)
	{
		inorderTraverse(current->left);
	}

	cout << current->id << "\n" << current->data << "\n\n";

	if (current->right != nullptr)
	{
		inorderTraverse(current->right);
	}

}

void tree::preorderTraverse(Node* current)
{

	cout << current->id << "\n" << current->data << "\n\n";

	if (current->left != nullptr)
	{
		preorderTraverse(current->left);
	}

	if (current->right != nullptr)
	{
		preorderTraverse(current->right);
	}

}

Node* tree::findNode(int id, Node* current)
{
	Node* target = nullptr;
	if (current == nullptr)
		return nullptr;

	if (current->id == id)
		return current;

	if (current->right != nullptr)
		target = findNode(id, current->right);
	if (current->left != nullptr && target == nullptr)
		target = findNode(id, current->left);

	return target;
}

bool tree::remove(int id)
{

	Node* current = root;
	Node* replacement = root;

	if (root == nullptr)
	{
		return false;
	}

	//Finding replacement
	while (current->right != nullptr || current->left != nullptr)
	{
		if (current->right != nullptr)
		{
			replacement = current;
			current = current->right;
		}
		else
		{
			replacement = current;
			current = current->left;
		}
	}

	if (replacement->left == current)
		replacement->left = nullptr;
	else
		replacement->right = nullptr;

	replacement = current;
	current = findNode(id, root);
	if (current == nullptr)
	{
		return false;
	}

	current->data = replacement->data;
	current->id = replacement->id;

	delete replacement;
	size--;
	return true;
	 


}

bool tree::add(int id, string data)
{
	int tempHeight = 1;
	Node* newNode = new Node;

	newNode->data = data;
	newNode->id = id;

	Node* current = root;

	if (root == nullptr)
	{
		root = newNode;
		height++;
		size++;
		return true;
	}
	
	while (true)
	{
		if (newNode->id < current->id && current->left != nullptr)
		{
			tempHeight++;
			current = current->left;
		}

		else if (newNode->id < current->id && current->left == nullptr)
		{
			current->left = newNode;
			tempHeight++;
			size++;

			if (tempHeight > height)
				height = tempHeight;

			return true;
		}

		if (newNode->id > current->id && current->right != nullptr)
		{
			tempHeight++;
			current = current->right;
		}

		else if (newNode->id > current->id && current->right == nullptr)
		{
			current->right = newNode;
			tempHeight++;
			size++;

			if (tempHeight > height)
				height = tempHeight;
			return true;
		}

	}
}


int tree::getNumberOfNodes()
{
	return size;
}

bool tree::isEmpty()
{
	if (size == 0)
		return true;
	return false;
}
