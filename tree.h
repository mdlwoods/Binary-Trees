
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
