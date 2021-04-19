// #ifndef __LIST_H__ // traditional way of doing it
// #define __LIST_H__

#pragma once //modern way of doing it

#include <iostream>

using namespace std;
#define DB_SIZE 1

struct Node
{
    string name;        //name of the person
    unsigned int phone; // phone number
};

class List
{
private:
    Node *dataBase; //address where the Node list is going to be stored
    int capacity;   //capacity of the list
    int size;       // number of legit elements in the list
public:
    List();  //declarer
    ~List(); //destroyer
    
    //getter functions
    int getCapacity() {return capacity;}
    int getSize() {return size;}

    void insert(Node data);
    void traverse();
    int search(string name); //return index of first found name
    void remove(int index); //delete at index and 
    int insert(Node data, int idx);
};

// #endif