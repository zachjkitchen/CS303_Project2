//Project2

#ifndef BTNODE_H
#define BTNODE_H

#include <string>

using namespace std;


class BTNode
{
public:
	BTNode(BTNode* leftChild, BTNode* rightChild, char data);

	char getLetter();
	string getCode();

	BTNode *left, *right;

	char data;

private:

};

#endif // !BTNODE_H
