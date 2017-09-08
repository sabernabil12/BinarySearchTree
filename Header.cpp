#include "Header.h"

BST::BST()
{
	topOfTree = NULL;
}
BST::~BST()
{
	cleanup(topOfTree);
}
void BST::cleanup(ONE_ITEM *tempPtr)
{
	if (tempPtr != NULL)
	{
		if (tempPtr->leftChild != NULL)
			cleanup(tempPtr->leftChild);

		if (tempPtr->rightChild != NULL)
			cleanup(tempPtr->rightChild);

		delete tempPtr;
	}

}
void BST::inOrder(ONE_ITEM *tempPtr)
{

	if (tempPtr != NULL)
	{
		inOrder(tempPtr->leftChild);

		cout << tempPtr->key << " " << tempPtr->data << endl;

		inOrder(tempPtr->rightChild);
	}
}

bool BST::traverseInOrder()  // LVR
{
	if (topOfTree == NULL)
		return false;
	else
		inOrder(topOfTree);
	return true;
}
void BST::preOrder(ONE_ITEM *tempPtr)
{
	if (tempPtr != NULL)
	{
		cout << tempPtr->key << " " << tempPtr->data << endl;
		preOrder(tempPtr->leftChild);
		preOrder(tempPtr->rightChild);
	}
}
bool BST::traversePreOrder() // VLR
{
	if (topOfTree == NULL)
		return false;
	else
		preOrder(topOfTree);
	return true;
}
void BST::postOrder(ONE_ITEM *tempPtr)
{
	if (tempPtr != NULL)
		
	{
		postOrder(tempPtr->leftChild);
		postOrder(tempPtr->rightChild);
		cout << tempPtr->key << " " << tempPtr->data << endl;
	}
}
bool BST::traversePostOrder() // LRV
 {
	if (topOfTree == NULL)
		return false;
	else
		postOrder(topOfTree);
	return true;
 }

bool BST::insertItem(int tempKey, string tempData)
{
	if (topOfTree == NULL)
	{
		topOfTree = new ONE_ITEM;
		topOfTree->key = tempKey;
		topOfTree->data = tempData;
		topOfTree->leftChild = NULL;
		topOfTree->rightChild = NULL;
		return true;
	}
	else
	{
		return insert(topOfTree, tempKey, tempData);
	}
}

bool BST::insert(ONE_ITEM *tempPtr, int tempKey, string tempData)
{
	if (tempKey == tempPtr->key)
	{
		return false;
	}
	else if (tempKey < tempPtr->key)
	{
		if (tempPtr->leftChild == NULL)
		{
			tempPtr->leftChild = new ONE_ITEM;
			tempPtr->leftChild->key = tempKey;
			tempPtr->leftChild->data = tempData;
			tempPtr->leftChild->leftChild = NULL;
			tempPtr->leftChild->rightChild = NULL;
			return true;
		}
		else
		{
			return insert(tempPtr->leftChild, tempKey, tempData);
		}
	}
	else
	{
		if (tempPtr->rightChild == NULL)
		{
			tempPtr->rightChild = new ONE_ITEM;
			tempPtr->rightChild->key = tempKey;
			tempPtr->rightChild->data = tempData;
			tempPtr->rightChild->leftChild = NULL;
			tempPtr->rightChild->rightChild = NULL;
			return true;
		}
		else
		{
			return insert(tempPtr->rightChild, tempKey, tempData);
		}
	}
}

bool BST::update(ONE_ITEM *tempPtr, int tempKey, string tempData)
{
	if (tempKey == tempPtr->key)
	{
		tempPtr->data = tempData;
		return true;
	}
	else if (tempKey < tempPtr->key)
	{
		if (tempPtr->leftChild == NULL)
		{
			return false;
		}
		else
		{
			return update(tempPtr->leftChild, tempKey, tempData);
		}
	}
	else
	{
		if (tempPtr->rightChild == NULL)
		{
			return false;
		}
		else
		{
			return update(tempPtr->rightChild, tempKey, tempData);
		}
	}
}

bool BST::updateItem(int tempKey, string tempData)
{
	

	if (topOfTree == NULL)
	{
		return false;
	}
	else
	{
		return update(topOfTree, tempKey, tempData);
	}
	
}
bool BST::deleteItem(int tempKey)
{
	return false;
}
