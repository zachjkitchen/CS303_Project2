//Project 2

#include "BTNode.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

void traverseBT_build(string element, BTNode *newRoot) {

	if (element.length() <= 1)
	{
		return;
	}

	if (element.length() == 2)
	{
		if (element[1] == '.')
		{
			if (newRoot->left)
			{
				cout << "setting CHARACTER " << element[0] << "left\n\n";
				newRoot->left->setData(element[0]);
			}
			cout << "placing CHARACTER " << element[0] << " left\n\n";
			newRoot->left = new BTNode(NULL, NULL, element[0]);
		}
		else if (element[1] == '_')
		{
			if (newRoot->right)
			{
				cout << "setting CHARACTER " << element[0] << "left\n\n";
				newRoot->right->setData(element[0]);
			}
			cout << "placing CHARACTER " << element[0] << " right\n\n";
			newRoot->right = new BTNode(NULL, NULL, element[0]);
		}

		return;
	}

	for (int j = 1; j < element.length(); j++)
	{
		if (element[j] == '.')
		{
			if (!newRoot->left)
			{
				cout << "placing NULL left\n";
				newRoot->left = new BTNode(NULL, NULL, NULL);
			}
			cout << "traversing left\n";
			cout << "passing " << element[0] + element.substr(j + 1, element.length()) << endl;
			traverseBT_build(element[0] + element.substr(j + 1, element.length()), newRoot->left);
		}
		else if (element[j] == '_')
		{
			if (!newRoot->right)
			{
				cout << "placing NULL right\n";
				newRoot->right = new BTNode(NULL, NULL, NULL);
			}
			cout << "traversing right\n";
			cout << "passing " << element[0] + element.substr(j + 1, element.length()) << endl;
			traverseBT_build(element[0] + element.substr(j + 1, element.length()), newRoot->right);
		}

		return;
	}
}

void traverseBT_encode(string letter, BTNode *newRoot) {
	/*
	//encode function
	void encode(BTNode *node, string str)
	{
		if (node == NULL)
			return;
		for (int i = 0; i < str.length(); i++)
		{
			if (*(node->data) == str[i]) {
				cout << (node->code);
				//will need to skip recursive functions if this is true
			}
			encode(node->left, str);
			encode(node->right, str);
		}
	}
	*/

}

char traverseBT_decode(string code, BTNode *newRoot) {

	if (code.length() == 1)
	{
		if (code[0] == '.')
		{
			cout << "returning left child: " << newRoot->left->data << endl;
			return newRoot->left->data;
		}
		else if (code[0] == '_')
		{
			cout << "returning right child: " << newRoot->right->data << endl;
			return newRoot->right->data;
		}
	}

	for (int j = 0; j < code.length() - 1; j++)
	{


		if (code[j] == '.')
		{
			cout << "traversing left\n";
			return traverseBT_decode(code.substr(j + 1, code.length()), newRoot->left);
		}
		else if (code[j] == '_')
		{
			cout << "traversing right\n";
			return traverseBT_decode(code.substr(j + 1, code.length()), newRoot->right);
		}
	}
}

void buildBT(BTNode *root, string arr[]) {

	for (int i = 0; i < 26; i++)
	{
		cout << "ELEMENT: " << arr[i] << endl;
		traverseBT_build(arr[i], root);
	}
}

//decode function
string decode(string str, BTNode *root)
{

	vector<string> codes;
	string ele;

	//populate vector of parsed codes
	int i = 0;
	while (str[i + 1] != NULL)
	{
		if (str[i] == ' ')
		{
			cout << "pushing " << ele << " to vector" << endl;
			codes.push_back(ele);
			ele = "";
		}
		else
		{
			ele += str[i];
		}
		i++;
	}
	cout << "pushing " << ele + str[i] << " to vector" << endl;
	codes.push_back(ele + str[i]);


	string result;
	for (int i = 0; i < codes.size(); i++)
	{
		result += traverseBT_decode(codes[i], root);
	}

	return result;
}


int main()
{
	//array to hold letters and morse code
	//read in from file instead?
	ifstream iStream;
	iStream.open("input.txt");
	string inputArr[27];
	string temp;
	int i = 0;

	while (i < 26)
	{
		iStream >> temp;
		inputArr[i] = temp;
		i++;
	}

	BTNode *root = new BTNode(NULL, NULL, NULL);

	buildBT(root, inputArr);

	string result = decode("._ ... ....", root);

	cout << result << endl;

	system("pause");
}

