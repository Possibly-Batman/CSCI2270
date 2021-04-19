#include <iostream>
#include "List.h"

using namespace std;

List::List()
{
    cout << "making a list babies" << endl;
    dataBase = new Node[DB_SIZE];
    size = 0;
    capacity = DB_SIZE;
}
List::~List()
{
    cout << "thios list's days are over" << endl;
    delete[] dataBase;
    dataBase = 0;
}
void List::insert(Node data){
    if (size < capacity) {
        dataBase[size] = data;
        size++;
    } else{
        capacity *= 2;
        Node* newDB = new Node[capacity];
        for(int i = 0; i < size; i++) newDB[i] = dataBase[i];
        //amortizing the cost of increasing size of List
        
        delete[] dataBase; //thanking it for it's services
        dataBase = newDB; //don't need dataBase = nullptr b/c of this step

        dataBase[size] = data;
        size++;

        cout << "yay array doubling" << endl;
    }
}

void List::traverse(){
    for(int i = 0; i < size; i++){
        cout << i << " : " << dataBase[i].name << " : " << dataBase[i].phone << endl;
    }
}


int List::search(string name){
    for(int i = 0; i < size; i++){
        if(dataBase[i].name == name){
            return i;
        }
    }
    return -1;
}
void List::remove(int index){
    if(index >=size){
        cerr << "incorrect index" << endl;
        return;
    } else if(index < 0){
        cerr << "incorrect index: can't be negative" << endl;
        return;
    }
    for(int i = index; i < size-1; i++){
        dataBase[i] = dataBase[i+1];
        size = size-1;
    }
} 
int List::insert(Node data, int idx){
    return 0;
}