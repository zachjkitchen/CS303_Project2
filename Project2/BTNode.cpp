//Project 2

#include "BTNode.h"

using namespace std;


BTNode::BTNode(BTNode* leftChild, BTNode* rightChild, char letter) {
	left = leftChild;
	right = rightChild;
	data = letter;
}