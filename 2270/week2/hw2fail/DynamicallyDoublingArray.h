#pragma once

#include <iostream>

using namespace std;

struct wordRecord
{
    string word; //or something
    int occurrences;
};

class DynamicallyDoublingArray
{
private:
    wordRecord *dataBase;
    int capacity;
    int size;
    int numberTimesDoubled;
    string badWordsArray[50];
public: 
    DynamicallyDoublingArray(string badWordsList);
    ~DynamicallyDoublingArray();

    int getCapacity(){return capacity;}
    int getSize(){return size;}
    int getNumberTimesDoubled(){return numberTimesDoubled;}

    int getTotalOccurrences();

    void add(string word);

    void sortDesc();
};