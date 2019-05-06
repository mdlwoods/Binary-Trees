#include "tree.h"


int main(int argc, char* argv[])
{
	tree myTree;
	srand(time(NULL));
	int size = stoi(argv[1]);
	bool IDS[9999] = { 0 };
	string data[] = { "Tina", "Gean", "Bob", "Linda", "louise", "Mort", "Bosco",
					"Belcher", "Michael", "Adrian", "Thor" ,"Iron Man", "Spider-Man",
					"Black Widow", "Thanos", "Loki", "Happy", "Pepper","Tony", "Wakanda" };
	
	

	for (int i = 0; i < size; i++)
	{
		int id = rand() % 8999 + 1000;
		while (IDS[id - 1000] == 1)
			id = rand() % 8999 + 1000;

		IDS[id - 1000] = 1;

		myTree.add(id, data[i]);

	}

	myTree.inorderTraverse(myTree.getRoot());

	cout << "\n\nChecking if empty: " << myTree.isEmpty() << endl;
	
	cout << "Adding nodes" << endl;
	myTree.add(8, "Matt");
	cout << "Height: " << myTree.getHeight() << endl;
	myTree.add(4, "Damon");
	cout << "Height: " << myTree.getHeight() << endl;
	myTree.add(5, "Chistopher");
	cout << "Height: " << myTree.getHeight() << endl;
	myTree.add(3, "Robin");
	cout << "Height: " << myTree.getHeight() << endl;
	myTree.add(9, "Charles");
	cout << "Height: " << myTree.getHeight() << endl;
	myTree.add(10, "Wallace");
	cout << "Height: " << myTree.getHeight() << endl;

	cout << "Size: " << myTree.getNumberOfNodes() << endl;

	myTree.inorderTraverse(myTree.getRoot());

	cout << "Checking if node 8 exists: " << myTree.contains(8) << endl;
	cout << "Checking if node 12 exists (it doesnt): " << myTree.contains(12) << endl;

	cout << "Removing node 9: " << myTree.remove(9) << endl;
	cout << "Checking if node 9 exists: " << myTree.contains(9) << endl;

	cout << "Post Order Traversal\n";
	myTree.postorderTraverse(myTree.getRoot());

	cout << "\n\n Pre Order Traversal\n";
	myTree.preorderTraverse(myTree.getRoot());

	cout << "Getting node 3: " << myTree.getEntry(3) << endl;
	
	cin.ignore();
}
