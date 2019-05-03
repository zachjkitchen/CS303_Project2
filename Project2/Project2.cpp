//Project 2

#include "BTNode.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

/*
//create a class for the Nodes that contains the letter and morse code
class MorseCode
{
	char *letter;
	char *code;
};

//function to build BT
*/

void traverseBT(string element, BTNode *newRoot) {
	
	if (element.length() == 2)
	{
		if (element[1] == '.')
		{
			cout << "placing CHARACTER left\n";
			newRoot->left = new BTNode(NULL, NULL, element[0]);
		}
		else if (element[1] == '-')
		{
			cout << "placing CHARACTER right\n";
			newRoot->right = new BTNode(NULL, NULL, element[0]);
		}

		return;
	}
	
	for (int j = 1; j < element.length(); j++)
	{
		if (element[j] == '.')
		{
			if (newRoot->left == NULL)
			{
				cout << "placing NULL left\n";
				newRoot->left = new BTNode(NULL, NULL, NULL);
			}
			cout << "traversing left\n";
			traverseBT(element.substr(j, element.length()), newRoot->left);
		}
		else if (element[j] == '-')
		{
			if (newRoot->left == NULL)
			{
				cout << "placing NULL right\n";
				newRoot->right = new BTNode(NULL, NULL, NULL);
			}
			cout << "traversing right\n";
			traverseBT(element.substr(j, element.length()), newRoot->right);
		}
	}
}
void buildBT(BTNode *root, string arr[]) {
	for (int i = 0; i < arr->length(); i++)
	{
		traverseBT(arr[i], root);
	}
}
/*
MorseCode buildBT(MorseCode arr[], BTNode* root, int i, ) //where i = 0
{
	Node *temp;
	//need to increment through entire array. maybe use for loop instead?
	if (i < sizeofarray)
	{
		temp = createNode(arr[i].letter, arr[i].code);
		root = temp;
		buildBT(arr, root->left, 2i + 1);
		buildBT(arr, root->right, 2i + 2);
	}
	return root;
}
//encode function
void encode(BTNode *node, string str)
{
	if (node == NULL)
		return;
	for (int i = 0; i < str.length(); i++)
	{
		if (*(node->letter) == str[i]) {
			cout << (node->code);
			//will need to skip recursive functions if this is true
		}
		encode(node->left, str);
		encode(node->right, str);
	}
}


//decode function
void decode(BTNode *node, string str)
{
	for (int i = 0; i < str.length(); i++) {
		//check for . or _
		if (str[i] == '.') {
			node = node->left;
			if (str[i + 1] == ' ' || (i + 1) == str.length()) {
				//either the end of string or deliminator, so we have finished trying to find letter
				cout << node.letter;
				//make the node = root

			}
		}
		else if (str[i] == '-') {
			node = node->right;
			if (str[i + 1] == ' ' || (i + 1) == str.length()) {
				//either the end of string or deliminator, so we have finished trying to find letter
				cout << node.letter;
				//make the node = root

			}
		}
	}
}
*/



int main()
{
	//array to hold letters and morse code
	//read in from file instead?
	ifstream iStream;
	iStream.open("input.txt");
	string inputArr[27];
	string temp;
	int i = 0;

	while (iStream)
	{
		iStream >> temp;
		inputArr[i] = temp;
		i++;
	}

	BTNode *root = new BTNode(NULL, NULL, NULL);

	buildBT(root, inputArr);

	//BTNode root = NULL;



	system("pause");

	/*
	MorseCode morseArr[] = {
		//order node data by depth
		//Depth 1: e, t
		{"E", "."}, {"T", "_"},
		//Depth 2: i, a, n, m
		{"I", ".."}, {"A", "._"}, {"N", "_."}, {"M", "__"},
		//Depth 3: s, u, r, w, d, k, g, o
		{"S", "..."}, {"U", ".._"}, {"R", "._."}, {"W", ".__"}, {"D", "_.."}, {"K", "_._"}, {"G", "__."}, {"O", "___"},
		//Depth 4: h, v, f, l, p, j, b, x, c, y, z, q
		{"H", "...."}, {"V", "..._"}, {"F", ".._."}, {"L", "._.."}, {"P", ".__."}, {"J", ".___"}, {"B", "_..."}, {"X", "_.._"}, {"C", "_._."}, {"Y", "_.__"}, {"Z", "__.."}, {"Q", "__._"}
	}
	*/
}

