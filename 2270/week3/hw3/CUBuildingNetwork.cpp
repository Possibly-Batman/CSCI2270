/****************************************************************/
/*                CUBuildingNetwork Implementation                 */
/****************************************************************/
/* TODO: Implement the member functions of class CUBuildingNetwork */
/*     This class uses a linked-list of CUBuilding structs to      */
/*     represet communication paths between buildings             */
/****************************************************************/

#include "CUBuildingNetwork.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;
/*
 * Purpose: Constructer for empty linked list
 * @param none
 * @return none
 */
CUBuildingNetwork::CUBuildingNetwork() {
    /* finished. do not touch. */
    head = NULL;
}

/*
 * Purpose: Check if list is empty
 * @return true if empty; else false
 */
bool CUBuildingNetwork::isEmpty()
{
/* finished. do not touch. */
    return (head == NULL);
}

/*
 * Purpose: Add a new building to the network
 *   between the building *previous and the Building that follows it in the network.
 * @param previous name of the Building that comes before the new Building
 * @param buildingName name of the new Building
 * @param numOfroom
 * @return none
 */
void CUBuildingNetwork::addBuildingInfo(CUBuilding* previous, string buildingName, int numOfroom) {
    CUBuilding* addition = new CUBuilding;
    // cout << "1" << endl;
    addition->name = buildingName;
    // cout << "2" << endl;
    addition->totalRoom = numOfroom;
    // cout << "3" << endl;
    addition->numberMessages = 0;
    // cout << "4" << endl;
    addition->message = "";
    // cout << "5" << endl;
    addition->next = NULL;
    
    if(previous == NULL){
        if(head != NULL){
            CUBuilding* temp = head;
            // cout << "6*" << endl;
            addition->next = temp;
        }
        head = addition;
        cout << "adding: " << buildingName << " (HEAD)" << endl;
        return;
    }
    CUBuilding* temp = previous->next;
    // cout << "6*" << endl;
    addition->next = temp;
    // cout << "7*" << endl;
    previous->next = addition;
    cout<<"adding: "<<buildingName<<" (prev: "<<previous->name << ")" << endl;
}


/*
 * Purpose: populates the network with the predetermined buildings
 * @param none
 * @return none
 */
void CUBuildingNetwork::loadDefaultSetup()
{
    //FLMG","DLC","ECOT","CASE","AERO","RGNT
    //2, 10, 6, 5, 4, 9
    addBuildingInfo(NULL, "FLMG", 2);
    addBuildingInfo(searchForBuilding("FLMG"), "DLC", 10);
    addBuildingInfo(searchForBuilding("DLC"), "ECOT", 6);
    addBuildingInfo(searchForBuilding("ECOT"), "CASE", 5);
    addBuildingInfo(searchForBuilding("CASE"), "AERO", 4);
    addBuildingInfo(searchForBuilding("AERO"), "RGNT", 9);
}

/*
 * Purpose: Search the network for the specified building and return a pointer to that node
 * @param buildingName name of the building to look for in network
 * @return pointer to node of buildingName, or NULL if not found
 *
 */
CUBuilding* CUBuildingNetwork::searchForBuilding(string buildingName)
{
    CUBuilding* current = head;
    while(current != NULL){
        if(current->name == buildingName){
            return current;
        }
        else{
            current = current->next;
        }
    }
    return NULL;
}


/*
 * Purpose:
 * @param string receiver
 * @param string msg
 */
void CUBuildingNetwork::transmitRoomInfo(string receiver) {
    // cout << "Empty list" << endl;
    // cout << "Building not found" << endl;
    // cout<<sender->name<<“[#messagesreceived:"<<sender->numberMessages<<"]received:"<<sender->message << endl;

    CUBuilding* current = head;
    
    if(head == NULL){
        cout << "Empty list" << endl;
        return;
    }
    
    if(searchForBuilding(receiver) == NULL){
        cout << "Building not found" << endl;
        return;
    }

    while(current != NULL){
        current->message = "available room at " + current->name + " is " + to_string(current->totalRoom);
        current->numberMessages++;

        cout << current->name << " [# messages received: " << current->numberMessages << "] received: " << current->message << endl;
        if(current->name == receiver){
            return;
        }
        current = current->next;
    }
}

/*
 * Purpose: prints the current list nicely
 * @param ptr head of list
 */
void CUBuildingNetwork::printNetwork() {
    CUBuilding* current = head;
    if(head = NULL){
        cout << "nothing in path" << endl;
    }
    cout << "== CURRENT PATH ==" << endl;
    while(current != NULL){
        cout << current->name << "(" << current->totalRoom << ")" << " -> ";
        current = current->next;
    }
    cout << "NULL" << endl;
    cout << "===" << endl;
}
