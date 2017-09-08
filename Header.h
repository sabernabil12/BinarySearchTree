#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class BST
{
private:
	class ONE_ITEM
	{
	public:
		int key;
		string data;

		//left child and right child
		ONE_ITEM *leftChild;
		ONE_ITEM *rightChild;
	};

	ONE_ITEM * topOfTree;
	void cleanup(ONE_ITEM *tempPtr);
	void inOrder(ONE_ITEM *tempPtr);
	void preOrder(ONE_ITEM *tempPtr);
	void postOrder(ONE_ITEM *tempPtr);
	bool insert(ONE_ITEM *tempPtr, int tempKey, string tempData);
	bool update(ONE_ITEM *tempPtr, int tempKey, string tempData);

public:
	BST();
	~BST();

	bool traverseInOrder(); // LVR
	bool traversePreOrder(); // VLR
	bool traversePostOrder(); // LRV

	bool insertItem(int tempKey, string tempData);
	bool updateItem(int tempKey, string tempData);
	bool deleteItem(int tempKey);

};
