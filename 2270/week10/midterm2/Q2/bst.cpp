#include <iostream>
#include "bst.hpp"

BST::BST() {
	root = NULL;
}

BST::~BST() {
	deleteTree(root);
	root = NULL;
}
void BST::deleteTree(Node* node) {
	if (node != NULL) {
		deleteTree(node->leftChild);
		deleteTree(node->rightChild);
		delete node;
	}
}

int searchCounterHelper(Node* current, int target){
	if(current->key == target){
		return 1; //counting comparisons on each return recursively
	}
	else if(current->key > target){
		if(current->leftChild == NULL){
			return 1;
		}
		else{
			return 1 + searchCounterHelper(current->leftChild, target);
		}
	}
	else{
		if(current->rightChild == NULL){
			return 1;
		}
		else{
			return 1 + searchCounterHelper(current->rightChild, target);
		}
	}
}

/*
** Implement the following function to return the count of comparisons, 
**   you may implement helper functions.
*/
int BST::searchCounter(int target) {
	return searchCounterHelper(root, target);
}
