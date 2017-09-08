#include "Header.h"

int main()
{
	int answer;
	int tempKey;
	string tempData;
	BST myBst;

	do
	{
		cout << "Choose from the following menu:" << endl << endl;
		cout << "1) Insert items." << endl;
		cout << "2) Print Items in Order" << endl;
		cout << "3) Print Items pre Order" << endl;
		cout << "4) Print Items post order" << endl;
		cout << "5) Update" << endl;
		cout << "6) Exit Program" << endl<<endl;
		
		
		cin >> answer;
		cout << "Response::" << endl;

		switch (answer)
		{
		case 1:
			cout << "Enter key and data: "<<endl;
			cin >> tempKey >> tempData;
			if (myBst.insertItem(tempKey, tempData) == false)
			{
				cout << "Item already exists:" << endl;
			}
		break;

		case 2:
			if (myBst.traverseInOrder() == false)
			{
				cout << "List is empty."<<endl;
			}

			break;
		case 3:
			if (myBst.traversePreOrder() == false)
			{
				cout << "List is empty." << endl;
			}

			break;
		case 4:
			if (myBst.traversePostOrder() == false)
			{
				cout << "List is empty." << endl;
			}

			break;
		case 5:
			cout << "Enter key and new data: " << endl;
			cin >> tempKey >> tempData;
			if (myBst.updateItem(tempKey, tempData) == false)
			{
				cout << "Item already exists:" << endl;
			}
			break;
		case 6:
			break;

		default:
			cout << "Invalid selection" << endl;
			break;

		}


	} while (answer != 6);

	return 0;

}
