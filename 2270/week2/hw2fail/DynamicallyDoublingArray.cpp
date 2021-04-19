#include <iostream>
#include <fstream>
#include "DynamicallyDoublingArray.h"

using namespace std;

DynamicallyDoublingArray::DynamicallyDoublingArray(string badWordsList)
{
    // cout << "being created" << endl;
    dataBase = new dataStruct[100];
    capacity = 100;
    size = 0;
    numberTimesDoubled = 0;

    ifstream inStream;           // stream for reading in file
    inStream.open(badWordsList); // open the file
    // cout << "being created1" << endl;
    int counter = 0;
    string word;
    while (inStream >> word && counter < 50)
    {
        // cout << counter << endl;
        badWordsArray[counter] = word;
        counter++;
    }

    inStream.close(); // close the file
    // cout << "being created2" << endl;
}

DynamicallyDoublingArray::~DynamicallyDoublingArray()
{
    delete[] dataBase;
    dataBase = nullptr;
    cout << "being killed" << endl;
}

void DynamicallyDoublingArray::add(string word)
{
    for (int i = 0; i < 50; i++)
    {
        if (badWordsArray[i] == word)
        {
            return;
        }
    }

    for (int i = 0; i < size; i++)
    {
        if (dataBase[i].word == word)
        {
            // cout << "increasing occurrence" << endl;
            dataBase[i].occurrences++;
            return;
        }
    }
    dataStruct data;
    data.word = word;
    data.occurrences = 1;
    // cout << "size:" << size << "capacity:" << capacity << endl;
    if (size < capacity)
    {
        // cout << "adding word" << endl;
        dataBase[size] = data;
        size++;
    }
    else
    {
        // cout << "adding word and doubling" << endl;
        capacity *= 2;
        numberTimesDoubled++;
        // cout << "1" << endl;
        dataStruct *replacementDataBase = new dataStruct[capacity];
        for (int i = 0; i < size; i++)
        {
            replacementDataBase[i] = dataBase[i];
        }
        // cout << "2" << endl;
        delete[] dataBase;
        dataBase = replacementDataBase;
        // cout << "3" << endl;
        dataBase[size] = data;
        size++;
        // cout << "4" << endl;
    }
}

void DynamicallyDoublingArray::sortDesc()
{ //this is going to be bad implementation, whatever
    bool isntSorted = true;
    while (isntSorted)
    {
        isntSorted = false;
        for (int i = 0; i < size - 1; i++){
            if (dataBase[i].occurrences < dataBase[i + 1].occurrences)
            {
                isntSorted = true;
                dataStruct temp = dataBase[i];
                dataBase[i] = dataBase[i + 1];
                dataBase[i + 1] = temp;
            }
        }
    }
}

int DynamicallyDoublingArray::getTotalOccurrences(){
    int totalOccurences = 0;
    for(int i = 0; i < size; i++){
        totalOccurences += dataBase[i].occurences;
    }
    return totalOccurences
}