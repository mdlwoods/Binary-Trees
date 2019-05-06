#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <string>
#include <time.h>


using namespace std;

struct Node
{
	int id;
	string data;
	Node* right = nullptr;
	Node* left = nullptr;
};

class tree
{
public:
	tree(); 
	~tree();
	bool isEmpty(); 
	int getHeight();
	int getNumberOfNodes(); 
	string getEntry(int id);
	bool add(int, string);
	bool remove(int id);
	bool clear(Node* current);
	bool contains(int id);
	void preorderTraverse(Node* current);
	void inorderTraverse(Node* current);
	void postorderTraverse(Node* current);
	Node* getRoot();
	Node* findNode(int id, Node* current);

private:
	Node* root;
	int size;
	int height;

};





#endif
