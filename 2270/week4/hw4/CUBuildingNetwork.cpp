/*******************************************************************/
/*                CUBuildingNetwork Implementation                 */
/*******************************************************************/
/* TODO: Implement the member functions of class CUBuildingNetwork */
/*       This class uses a linked-list of CUBuilding nodes to      */
/*       represent communication paths between buildings           */
/*******************************************************************/

#include "CUBuildingNetwork.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;

/*
 * Purpose: Constructor for empty linked list
 * @param none
 * @return none
 */
CUBuildingNetwork::CUBuildingNetwork()
{
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
 *   between the CUBuilding *previous and the CUBuilding that follows it in the network.
 * @param previous name of the Building that comes before the new Building
 * @param buildingName name of the new Building
 * @param numOfroom
 * @return none
 */
void CUBuildingNetwork::addBuildingInfo(CUBuilding *previous, string buildingName, int numOfroom)
{
    CUBuilding *addition = new CUBuilding;
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

    if (previous == NULL)
    {
        if (head != NULL)
        {
            CUBuilding *temp = head;
            // cout << "6*" << endl;
            addition->next = temp;
        }
        head = addition;
        cout << "adding: " << buildingName << " (HEAD)" << endl;
        return;
    }
    CUBuilding *temp = previous->next;
    // cout << "6*" << endl;
    addition->next = temp;
    // cout << "7*" << endl;
    previous->next = addition;
    cout << "adding: " << buildingName << " (prev: " << previous->name << ")" << endl;
}

/*
 * Purpose: populates the network with the predetermined CUBuildings
 * @param none
 * @return none
 */
void CUBuildingNetwork::loadDefaultSetup()
{ //delete the list before adding this stuff
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
CUBuilding *CUBuildingNetwork::searchForBuilding(string buildingName)
{
    CUBuilding *current = head;
    while (current != NULL)
    {
        if (current->name == buildingName)
        {
            return current;
        }
        else
        {
            current = current->next;
        }
    }
    return NULL;
}

/*
 * Purpose: Relay a message through the linked list until the specified CUBuilding
 * @param string receiver
 * @param string msg
 */
void CUBuildingNetwork::transmitRoomInfo(string receiver)
{
    // cout << "Empty list" << endl;
    // cout << "Building not found" << endl;
    // cout<<sender->name<<“[#messagesreceived:"<<sender->numberMessages<<"]received:"<<sender->message << endl;

    CUBuilding *current = head;

    if (head == NULL)
    {
        cout << "Empty list" << endl;
        return;
    }

    if (searchForBuilding(receiver) == NULL)
    {
        cout << "Building not found" << endl;
        return;
    }

    while (current != NULL)
    {
        current->message = "available room at " + current->name + " is " + to_string(current->totalRoom);
        current->numberMessages++;

        cout << current->name << " [# messages received: " << current->numberMessages << "] received: " << current->message << endl;
        if (current->name == receiver)
        {
            return;
        }
        current = current->next;
    }
}

/*
 * Purpose: prints the current list nicely
 * @param ptr head of list
 */
void CUBuildingNetwork::printNetwork()
{
    CUBuilding *current = head;
    if (head = NULL)
    {
        cout << "nothing in path" << endl;
    }
    cout << "== CURRENT PATH ==" << endl;
    while (current != NULL)
    {
        cout << current->name << "(" << current->totalRoom << ")"
             << " -> ";
        current = current->next;
    }
    cout << "NULL" << endl;
    cout << "===" << endl;
}

/****************************************************/
/*  ASSIGNMENT 4: Functions to be completed below.  */
/****************************************************/

/*
 * Purpose: Delete the CUBuilding in the network with the specified name.
 * @param buildingName name of the CUBuilding to delete in the network
 * @return none
 */
void CUBuildingNetwork::deleteCUBuilding(string buildingName)
{
    bool hasDeleted = false;
    if (buildingName == head->name)
    {
        // cout << "poggers1" << endl;
        CUBuilding *temp = head;
        head = head->next;
        delete temp;
        temp = nullptr;
        hasDeleted = true;
    }
    else
    {
        // cout << "poggers2" << endl;
        CUBuilding *current = head->next;
        CUBuilding *previous = head;
        while (!hasDeleted && current != NULL)
        {
            if (current->name == buildingName)
            {
                // cout << "poggers3" << endl;
                CUBuilding *temp = current;
                // cout << "poggers3" << endl;
                previous->next = current->next;
                // cout << "poggers3" << endl;
                delete temp;
                // cout << "poggers3" << endl;
                temp = nullptr;
                hasDeleted = true;
            }
            else
            {
                // cout << "poggers4" << endl;
                current = current->next;
                previous = previous->next;
            }
        }
    }
    if (!hasDeleted)
    {
        cout << "Building does not exist." << endl;
    }
    // cout << "poggers5" << endl;
    // TODO: Complete this function
}

/*
 * Purpose: deletes all CUBuildings in the network starting at the head CUBuilding.
 * @param: none
 * @return: none
 */
void CUBuildingNetwork::deleteEntireNetwork()
{
    while (head != NULL)
    {
        cout << "deleting: " << head->name << endl;
        CUBuilding *temp = head;
        head = head->next;
        if (temp != NULL)
        {
            delete temp;
            temp = nullptr;
        }
    }
    cout << "Deleted network" << endl;
    // TODO: Complete this function
}

/*
* Purpose: Creates a loop from last node to the CUBuilding specified.
* @param buildingName name of the CUBuilding to loop back
* returns the last node before loop creation (to break the loop)
*/
CUBuilding *CUBuildingNetwork::createLoop(string buildingName)
{
    CUBuilding *desired = searchForBuilding(buildingName);
    CUBuilding *current = desired;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = desired;
    return current;
    // TODO: Complete this function
}

/*
 * Purpose: to detect loop in the linked list
 * @return: true if loop is detected, else false
 */
bool CUBuildingNetwork::detectLoop()
{
    CUBuilding *slow = head;
    CUBuilding *fast = head;
    while(fast->next != NULL && fast->next->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            return true;
        }
    }
    return false;
    // TODO: Complete this function
}

/*
 * Purpose: Take the chunk of nodes from start index to end index
 *          Move that chunk to the end of the List
 * @param: start_index, end_index
 * @return: none
 */
void CUBuildingNetwork::readjustNetwork(int start_index, int end_index)
{
    if(head == NULL){
        cout << "Linked List is Empty" << endl;
        return;
    }
    if(end_index < 0){
        cout << "Invalid end index" << endl;
        return;
    }
    if(start_index > end_index){
        cout << "Invalid indices" << endl;
        return;
    }
    if(start_index == 0){
        int counter = 1;
        // cout << "moving the head" << endl;
        CUBuilding *current = NULL;
        // cout << "poggers0" << endl;
        current = head->next;
        // cout << "poggers1" << endl;
        while(counter != end_index){
            // cout << "poggers2" << endl;
            if(current->next == NULL){
                cout << "Invalid end index" << endl;
                return;
            }
            current = current->next;
            counter++;
        }
        CUBuilding *temp = head;
        head = current->next;
        // cout << "poggers3" << endl;
        CUBuilding *last = current->next;
        current->next = NULL;
        // cout << "poggers4" << endl;
        while(last->next != NULL){
            // cout << "going to last" << endl;
            last = last->next;
        }
        last->next = temp;
        return;
    }

    //if endindex is >= to last node index
    //of startindex is >= to last node index
    CUBuilding *before_start = head;
    CUBuilding *current = head->next;
    int counter = 1;
    while(counter < start_index){
        if(current->next == NULL){
            cout << "Invalid start index" << endl;
            return;
        }
        before_start = before_start->next;
        current = current->next;
        counter++;
    }
    while(counter < end_index){
        if(current->next == NULL){
            cout << "Invalid end index" << endl;
            return;
        }
        current = current->next;
        counter++;
    }
    if(current->next == NULL){
        cout << "Invalid end index" << endl;
        return;
    }
    CUBuilding *temp = before_start->next;
    CUBuilding *temp2 = current;
    current = current->next;
    temp2->next = NULL;
    before_start->next = current;
    while(current->next != NULL){
        current = current->next;
    }
    current->next = temp;
    // TODO: Complete this function
}

/*
 * Purpose: Destructor to delete the entire list on program termination
 * @param none
 * @return none
 */
CUBuildingNetwork::~CUBuildingNetwork()
{
    // TODO: Complete this function
}
