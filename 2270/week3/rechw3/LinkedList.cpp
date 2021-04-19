#include "LinkedList.h"

using namespace std;

// Add a new node to the list
void LinkedList::insert(Node* prev, int newKey){

  //Check if head is Null i.e list is empty
  if(head == NULL){
    head = new Node;
    head->key = newKey;
    head->next = NULL;
  }

  // if list is not empty, look for prev and append our node there
  else if(prev == NULL)
  {
      Node* newNode = new Node;
      newNode->key = newKey;
      newNode->next = head;
      head = newNode;
  }

  else{

      Node* newNode = new Node;
      newNode->key = newKey;
      newNode->next = prev->next;
      prev->next = newNode;

    }
  }


// TODO: SILVER PROBLEM
// Delete node at a particular index
bool LinkedList::deleteAtIndex(int n)
{
  bool isDeleted = false;

  if(head == NULL){
    cout<< "List is already empty"<<endl;
    return isDeleted;
  }

  // Special case to delete the head
    if (n == 0) {
      if(head->next == NULL){
        delete head;
        head = NULL;
        return true;
      } else {
        Node *temp = head;
        head = head->next;
        delete temp;
        temp = nullptr;
        return true;
      }
    }

  Node *current = head->next;
  Node *prev = head;
  int index = 1;

  while(current != NULL && index < n){
    current = current->next;
    prev = prev->next;
    index++;
  }
  if(index != n){
    return false; //index out of bounds
  }
  else{
    Node *temp = current; //storing for memory deletion
    prev->next = current->next; // no longer in linked list

    delete temp;
    temp = nullptr; //pow dead
    return true;
  }

    // TODO done above

	return isDeleted;
}

// TODO: GOLD PROBLEM
// Swap the first and last nodes (don't just swap the values)
bool LinkedList::swapFirstAndLast()
{
    bool isSwapped = false;

    if(head == NULL) {
        cout << "List is empty. Cannot swap" << endl;
        return false;
    }
    if(head->next == NULL){
      return true; // technically swapped? 
    }
    Node *first = head;
    Node *b4last = head;
    Node *last = head->next;
    while(last->next != NULL){ //assigning values
      last = last->next;
      b4last = b4last->next;
    }
    if(last == first->next){
      head = last;
      last->next = first;
      first->next = NULL;
      return true;
    }
    else{
      Node *firstNextTemp = first->next;
      b4last->next = first;
      first->next = NULL;
      head = last;
      last->next = firstNextTemp;
      return true;
    }
    
    

    // TODO (take care of the edge case when your linkedlist has just 2 nodes)

    return isSwapped;
}

// Print the keys in your list
void LinkedList::printList(){
  Node* temp = head;

  while(temp->next != NULL){
    cout<< temp->key <<" -> ";
    temp = temp->next;
  }

  cout<<temp->key<<endl;
}

// Search for a specified key and return a pointer to that node
Node* LinkedList::searchList(int key) {

    Node* ptr = head;
    while (ptr != NULL && ptr->key != key)
    {
        ptr = ptr->next;
    }
    return ptr;
}
