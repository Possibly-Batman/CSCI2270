/****************************************************************/
/*      ONLY COMPLETE THE FUNCTIONS OF CUBUuildingNetwork Class */
/****************************************************************/
/*  DONOT change the class and main           */
/****************************************************************/

//#pragma once
#include <iostream>
#include <fstream>
using namespace std;
/*------ Contents of .hpp file. DONOT change-------*/
// CUBuilding: node struct that will be stored in the BuildingNetwork
struct CUBuilding
{
    string name;         // name of the building
    string message;      // message this building has received
    int numberMessages;  // no. of messages passed through this building
    CUBuilding *next;       // pointer to the next building
    int totalRoom;

};

// class for storing and manipulating linked-list of CU Buildings
class CUBuildingNetwork {
    private:
        CUBuilding* head;  // pointer to head of linked list of CU Buildings

    public:
        // You will need to define the below unfinished methods in CUBuildingNetwork.cpp
        CUBuildingNetwork();
        bool isEmpty();
        void addBuildingInfo(CUBuilding* previous, string buildingName, int totalRoom);
        void loadDefaultSetup();
        CUBuilding* searchForBuilding(string buildingName);
        void transmitRoomInfo(string receiver);
        void printNetwork();
};
//------------ hpp file ends------------------------------------------//


using namespace std;

/************************************************
    Definitions for main.cpp . DONOT change here
************************************************/
void displayMenu()
{
    // COMPLETE
    cout << "Select a numerical option:" << endl;
    cout << "+=====Main Menu=========+" << endl;
    cout << " 1. Build Network " << endl;
    cout << " 2. Print Network Path " << endl;
    cout << " 3. Broadcast Room Info " << endl;
    cout << " 4. Add Building " << endl;
    cout << " 5. Quit " << endl;
    cout << "+-----------------------+" << endl;
    cout << "#> ";
} 

int main(int argc, char* argv[])
{
    
    CUBuildingNetwork CUBuildingNet;
    int opt = 0;
    string s, s1, s2;

    while(opt != 5) {

        displayMenu();

        getline(cin, s);
        opt = stoi(s);

        switch(opt) {
            case 1: {
                CUBuildingNet.loadDefaultSetup();
                CUBuildingNet.printNetwork();
                break;
            }

            case 2: {
                CUBuildingNet.printNetwork();
                break;
            }

            case 3: {
                cout << "Enter name of the recipient to receive the message: "<< endl;
                getline(cin, s1);

                //cout << "Enter the message to send: " << endl;
                //getline(cin, s2);

                cout << endl;

                CUBuildingNet.transmitRoomInfo(s1);

                break;
            }

            case 4: {
                cout << "Enter a new building name: " << endl;
                getline(cin, s1);

                string roomNum;
                cout << "Enter total room number: " << endl;
                getline(cin, roomNum);

                cout << "Enter the previous building name (or First): " << endl;
                getline(cin, s2);

                while(!(s2 == "First" || CUBuildingNet.searchForBuilding(s2))) {
                    cout << "INVALID(previous building name)...Please enter a VALID building name!" << endl;
                    getline(cin, s2);
                }

                if(s2 == "First") {
                    CUBuildingNet.addBuildingInfo(NULL, s1, stoi(roomNum));
                }
                else {
                    CUBuildingNet.addBuildingInfo(CUBuildingNet.searchForBuilding(s2), s1, stoi(roomNum));
                }

                CUBuildingNet.printNetwork();
                break;
            }

            case 5: {
                cout << "Quitting..." << endl;
                break;
            }

        }
    }

    cout << "Goodbye!" << endl;

    return 0;
    
}

/************************************************
      Definitions from CUBuildingNetwork.cpp
      Complete the functions
************************************************/
CUBuildingNetwork::CUBuildingNetwork() {
    /* finished. do not touch. */
    head = NULL;
}

bool CUBuildingNetwork::isEmpty()
{
/* finished. do not touch. */
    return (head == NULL);
}

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

void CUBuildingNetwork::loadDefaultSetup()
{
    //FLMG","DLC","ECOT","CASE","AERO","RGNT
    //2, 10, 6, 5, 4, 9
    addBuildingInfo(NULL, "FLMG", 2);
    // printNetwork();
    addBuildingInfo(searchForBuilding("FLMG"), "DLC", 10);
    // printNetwork();
    addBuildingInfo(searchForBuilding("DLC"), "ECOT", 6);
    // printNetwork();
    addBuildingInfo(searchForBuilding("ECOT"), "CASE", 5);
    // printNetwork();
    addBuildingInfo(searchForBuilding("CASE"), "AERO", 4);
    // printNetwork();
    addBuildingInfo(searchForBuilding("AERO"), "RGNT", 9);
    // printNetwork();
}

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

void CUBuildingNetwork::transmitRoomInfo(string receiver) {
    // cout << "Empty list" << endl;
    // cout << "Building not found" << endl;
    // cout<<sender->name<<“[#messagesreceived:"<<sender->numberMessages<<"]received:"<<sender->message << endl;

    CUBuilding* current = head;
    if(current == NULL){
        cout << "Empty list" << endl;
        // printNetwork();
        return;
    }
    
    if(searchForBuilding(receiver) == NULL){
        cout << "Building not found" << endl;
        // printNetwork();
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

void CUBuildingNetwork::printNetwork() {
    CUBuilding* current = head;
    if(head == NULL){
        cout << "== CURRENT PATH ==" << endl;
        cout << "nothing in path" << endl;
        cout << "===" << endl;
        return;
    }
    cout << "== CURRENT PATH ==" << endl;
    while(current != NULL){
        cout << current->name << "(" << current->totalRoom << ")" << " -> ";
        current = current->next;
    }
    cout << "NULL" << endl;
    cout << "===" << endl;
}