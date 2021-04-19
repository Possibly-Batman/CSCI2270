#include <iostream>
#include <fstream>
#include "MovieTree.hpp"

using namespace std;

LLMovieNode *getLLMovieNode(int r, std::string t, int y, float q)
{
	LLMovieNode *lmn = new LLMovieNode();
	lmn->ranking = r;
	lmn->title = t;
	lmn->year = y;
	lmn->rating = q;
	lmn->next = NULL;
	return lmn;
}

/* ------------------------------------------------------ */
MovieTree::MovieTree()
{
	root = NULL;
}

void DestoryMovieTreeHelper(TreeNode *current){
	if(current != nullptr){
		// cout << "current: " << current << endl;
		DestoryMovieTreeHelper(current->leftChild);
		// cout << "current: " << current << endl;
		DestoryMovieTreeHelper(current->rightChild); 
		// cout << "current: " << current << endl;
		LLMovieNode *curr;
		// cout << "current: " << current << endl;
		if(current->head != nullptr){
			curr = current->head->next;
		}
		// cout << "current: " << current << endl;
		LLMovieNode *prev = current->head;
		// cout << "current: " << current << endl;
		while(prev != nullptr){
			delete prev;
			prev = curr;
			if(curr != nullptr){
				curr = curr->next;
			}
		}
		delete current;
		// cout << "current: " << current << endl;
		return;
	}
}

MovieTree::~MovieTree()
{
	// cout << "root: " << root << endl;
	DestoryMovieTreeHelper(root);
}

/* ------------------------------------------------------ */
void inorderTraversalHelper(TreeNode *root)
{
	if (root == NULL)
	{
		return;
	}

	inorderTraversalHelper(root->leftChild);
	cout << root->titleChar << " ";
	inorderTraversalHelper(root->rightChild);
}

void MovieTree::inorderTraversal()
{
	inorderTraversalHelper(root);
	cout << endl;
}

/* ------------------------------------------------------ */
TreeNode *searchCharHelper(TreeNode *curr, char key)
{
	if (curr == NULL)
		return curr;
	else if (curr->titleChar == key)
		return curr;
	else if (curr->titleChar > key)
		return searchCharHelper(curr->leftChild, key);
	else
		return searchCharHelper(curr->rightChild, key);
}

TreeNode *MovieTree::searchCharNode(char key)
{
	return searchCharHelper(root, key);
}

/* ------------------------------------------------------ */

void showMovieCollectionHelper(TreeNode *current)
{
	if (current != nullptr)
	{
		showMovieCollectionHelper(current->leftChild);

		if (current->head != nullptr)
		{
			cout << "Movies starting with letter: " << current->titleChar << endl;
			LLMovieNode *traversalPointer = current->head;
			while (traversalPointer != nullptr)
			{
				cout << " >> " << traversalPointer->title << " " << traversalPointer->rating << endl;
				traversalPointer = traversalPointer->next;
			}
		}

		showMovieCollectionHelper(current->rightChild);
	}
	return;
}

void MovieTree::showMovieCollection()
{
	showMovieCollectionHelper(root);
}

int alphabeticalSorting(string first, string second)
{
	for (unsigned int i = 0; i < first.length(); i++)
	{
		char firstLet = tolower(first.at(i));
		char secondLet = tolower(second.at(i));
		if (firstLet < secondLet)
		{
			return 1;
		}
		if (firstLet > secondLet)
		{
			return -1;
		}
	}
	return 0;
}

void MovieTree::insertMovie(int ranking, string title, int year, float rating)
{
	string testervar = "";
	// cout << "loggers" << endl;
	LLMovieNode *toAdd = new LLMovieNode;
	// cout << "foggers" << endl;
	toAdd->ranking = ranking;
	// cout << "zoggers" << endl;
	toAdd->title = title;
	// cout << "toggers" << endl;
	toAdd->year = year;
	// cout << "coggers" << endl;
	toAdd->rating = rating;
	TreeNode *current = root;

	// cout << "poggers" << endl;
	if (current == nullptr)
	{
		// cout << "Aoggers" << endl;
		TreeNode *newLad = new TreeNode;
		newLad->head = toAdd;
		newLad->titleChar = toAdd->title.at(0);
		root = newLad;
		cout << testervar;
		return;
	}

	while (current->titleChar != toAdd->title.at(0))
	{

		if (alphabeticalSorting(string(1, current->titleChar), toAdd->title) == 1)
		{
			if (current->rightChild != nullptr)
			{
				current = current->rightChild;
			}
			else
			{
				//cout << "current: " << current << "current.right: " << current->rightChild << endl;
				TreeNode *newLad = new TreeNode;
				newLad->head = toAdd;
				newLad->titleChar = toAdd->title.at(0);
				current->rightChild = newLad;
				newLad->parent = current;
				cout << testervar;
				return;
			}
		}
		else
		{ //same but for left
			if (current->leftChild != nullptr)
			{
				current = current->leftChild;
			}
			else
			{
				TreeNode *newLad = new TreeNode;
				newLad->head = toAdd;
				newLad->titleChar = toAdd->title.at(0);
				current->leftChild = newLad;
				newLad->parent = current;
				cout << testervar;
				return;
			}
		}
	}
	//current is pointing to the correct TreeNode now.
	if (alphabeticalSorting(current->head->title, toAdd->title) == -1)
	{
		toAdd->next = current->head;
		current->head = toAdd;
		cout << testervar;
		return;
	}
	LLMovieNode *curr = current->head->next;
	LLMovieNode *prev = current->head;
	while (curr != nullptr)
	{
		if (alphabeticalSorting(curr->title, toAdd->title) == -1)
		{
			toAdd->next = curr;
			prev->next = toAdd;
			cout << testervar;
			return;
		}
		curr = curr->next;
		prev = prev->next;
	}
	toAdd->next = curr;
	prev->next = toAdd;
	cout << testervar;
	return;
}

void MovieTree::removeMovieRecord(std::string title)
{
	TreeNode *current = root;
	while (current != nullptr)
	{

		if (current->titleChar == title.at(0))
		{
			if (current->head->title == title)
			{
				LLMovieNode *temp = current->head;
				current->head = current->head->next;
				delete temp;
				temp = nullptr;
				return;
			}
			LLMovieNode *curr = current->head->next;
			LLMovieNode *prev = current->head;
			while (curr != nullptr)
			{
				if (curr->title == title)
				{
					prev->next = curr->next;
					delete curr;
					curr = nullptr;
					return;
				}
				curr = curr->next;
				prev = prev->next;
			}
		}

		if (alphabeticalSorting(string(1, current->titleChar), title) == 1)
		{
			current = current->rightChild;
		}
		else
		{
			current = current->leftChild;
		}
	}
	cout << "Movie not found." << endl;
}

void MovieTree::leftRotation(TreeNode *curr)
{
	if(curr == root){
		TreeNode *x = curr;
		TreeNode *y = curr->rightChild;

		y->parent = NULL;
		x->parent = y;
		root = y;

		TreeNode *yLeft = y->leftChild;
		x->rightChild = yLeft;
		y->leftChild = x;

		return;
	}	
	if (curr != root)
	{
		TreeNode *x = curr;
		TreeNode *y = curr->rightChild;

		bool isRight;
		if (x->parent->rightChild == x)
		{
			isRight = true;
		}

		TreeNode *xParent = x->parent;
		y->parent = xParent;
		x->parent = y;

		TreeNode *yLeft = y->leftChild;
		x->rightChild = yLeft;
		y->leftChild = x;

		if (isRight)
		{
			xParent->rightChild = y;
		}
		else
		{
			xParent->leftChild = y;
		}
		return;
	}
}
