#include <iostream> // predefined header file (defined for you)
using namespace std;

#include "SLL.hpp" // your own header file
// <> vs "" -- compiler looks for the file in the C++ implementation
// vs in the current directory


SLL::SLL(){ // constructor definition
	head = nullptr;
}

SLL::~SLL(){
	Node* crawler;

	while(head!=nullptr){
		crawler = head->next;
		delete head;
		head = crawler;
	}
}


void SLL::displayList(){
	Node* crawler = head;
	while( crawler != nullptr ){
		cout << crawler->key << "->";
		crawler = crawler->next;
	}

	cout << "END" << endl;
}


void SLL::insert(Node* afterMe, char newValue){

	if(head == nullptr){
		// first case: empty list
		// add new node and make head point to it
		head = new Node;
		head->key = newValue;
		head->next = nullptr; // what if we forget this line?
	}
	else if(afterMe == nullptr){
		// This condition implies that the list is not empty, but
		// the caller wants to add node before the head node
		Node* newNode = new Node;
		newNode->key = newValue;
		newNode->next = head;
		head = newNode;
		// at this point, we can test our code for this use case

	}
	else{
		Node* newNode = new Node;
		newNode->key = newValue;
		newNode->next = afterMe->next;
		afterMe->next = newNode;
	}


}

bool SLL::palindrome(){
	if(head == NULL || head->next == NULL){
		return true;
	}
	int counter = 0;
	Node *current = head;
	while(current != NULL){
		counter++;
		current = current->next;
	}
	char* arr = new char[counter];
	counter = 0;
	current = head;
	while(current != NULL){
		arr[counter] = current->key;
		counter++;
		current = current->next;
	}

	for(int i =0; i < counter / 2; i++){
		if(arr[i] != arr[counter - 1 - i]){
			// cout << "arr[i]: " << arr[i] << " arr[counter-1-i]: " << arr[counter - 1 - i] << endl; was for testing
			delete[] arr;
			arr = nullptr;
			return false;
		}
	}
	delete[] arr;
	arr = nullptr;
	/*
	    * TODO your function definition goes here
	*/
	return true;
}

char SLL::atIndex(int i){
	if(i < 0){
		return '\0';
	}
	int counter = 0;
	Node *current = head;
	while(current != NULL && counter != i){
		counter++;
		current = current->next;
	}
	if(counter == i){
		return current->key;
	}
	else{
		return '\0';
	}
}



