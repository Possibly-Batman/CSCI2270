#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

struct wordRecord
{
    string word;
    int count;
};

void getIgnoreWords(const char *ignoreWordFileName, string ignoreWords[])
{

    ifstream inStream;                 // stream for reading in file
    inStream.open(ignoreWordFileName); // open the file

    if (!inStream.is_open())
    {
        std::cout << "Failedtoopen" << ignoreWordFileName << std::endl;
    }

    int counter = 0;
    string word;
    while (inStream >> word && counter < 50)
    {
        ignoreWords[counter] = word;
        counter++;
    }

    inStream.close();
}

bool isIgnoreWord(string word, string ignoreWords[]);

int getTotalNumberNonIgnoreWords(wordRecord distinctWords[], int length);

void sortArray(wordRecord distinctWords[], int length);

void printTenFromN(wordRecord distinctWords[], int N, int totalNumWords);

int main(int argc, char const *argv[])
{
    int N = stoi(argv[1]);
    string analyziedFile = argv[2];
    // argv[3] is the ignored file name

    ifstream inStream;            // stream for reading in file
    inStream.open(analyziedFile); // open the file

    string badWordsArray[50];
    getIgnoreWords(argv[3], badWordsArray);

    wordRecord *distinctWords = new wordRecord[100];
    int numberTimesDoubled = 0;
    int numberDistinctWords = 0;
    int capacity = 100;

    string word;
    while (inStream >> word)
    {
        if (!isIgnoreWord(word, badWordsArray))
        {
            bool countedWord = false;
            for (int i = 0; i < numberDistinctWords; i++)
            {
                if (distinctWords[i].word == word)
                {
                    // cout << "increasing occurrence" << endl;
                    distinctWords[i].count++;
                    countedWord = true;
                }
            }
            if (!countedWord)
            {
                wordRecord data;
                data.word = word;
                data.count = 1;
                // cout << "size:" << size << "capacity:" << capacity << endl;
                if (numberDistinctWords < capacity)
                {
                    // cout << "adding word" << endl;
                    distinctWords[numberDistinctWords] = data;
                    numberDistinctWords++;
                }
                else
                {
                    // cout << "adding word and doubling" << endl;
                    capacity *= 2;
                    numberTimesDoubled++;
                    // cout << "1" << endl;
                    wordRecord *replacementDataBase = new wordRecord[capacity];
                    for (int i = 0; i < numberDistinctWords; i++)
                    {
                        replacementDataBase[i] = distinctWords[i];
                    }
                    // cout << "2" << endl;
                    delete[] distinctWords;
                    distinctWords = replacementDataBase;
                    // cout << "3" << endl;
                    distinctWords[numberDistinctWords] = data;
                    numberDistinctWords++;
                    // cout << "4" << endl;
                }
            }
        }
    }
    inStream.close(); // close the file

    sortArray(distinctWords, numberDistinctWords);

    int totalNumWords = getTotalNumberNonIgnoreWords(distinctWords, numberDistinctWords);

    cout << "Array doubled: " << numberTimesDoubled << endl;
    cout << "Distinct non-common words: " << numberDistinctWords << endl;
    cout << "Total non-common words: " << totalNumWords << endl;
    cout << "Probability of next 10 words from rank " << N << endl;
    cout << "---------------------------------------" << endl;
    printTenFromN(distinctWords, N, totalNumWords);

    // cout << distinctWords[0].word << endl;
    // cout << distinctWords[1].word << endl;
    // cout << distinctWords[25].word << endl;
    // cout << distinctWords[26].word << endl;

    delete[] distinctWords;
    distinctWords = nullptr;
}

bool isIgnoreWord(string word, string ignoreWords[])
{
    for (int i = 0; i < 50; i++)
    {
        if (ignoreWords[i] == word)
        {
            return true;
        }
    }
    return false;
}

int getTotalNumberNonIgnoreWords(wordRecord distinctWords[], int length)
{
    int totalNumberNonIgnoreWords = 0;
    for (int i = 0; i < length; i++)
    {
        totalNumberNonIgnoreWords += distinctWords[i].count;
    }
    return totalNumberNonIgnoreWords;
}

void sortArray(wordRecord distinctWords[], int length)
{
    bool isntSorted = true;
    while (isntSorted)
    {
        isntSorted = false;
        for (int i = 0; i < length - 1; i++)
        {
            if (distinctWords[i].count < distinctWords[i + 1].count)
            {
                isntSorted = true;
                wordRecord temp = distinctWords[i];
                distinctWords[i] = distinctWords[i + 1];
                distinctWords[i + 1] = temp;
            }
        }
    }
}

bool isSorted(string str1, string str2){
    for(int i = 0; i < str1.length(); i++){
        if((char)(str1.at(i)) > (char)(str2.at(i))){
            return false;
        } else if((char)(str1.at(i)) < (char)(str2.at(i))){
            return true;
        }
    }
    return true;
}

void sortAlphabetically(wordRecord sortingWords[]){
    bool isntSorted = true;
    while(isntSorted){
        isntSorted = false;
        for(int i = 0; i < 9; i++){
            if(sortingWords[i].count == sortingWords[i+1].count && !isSorted(sortingWords[i].word, sortingWords[i+1].word)){
                isntSorted = true;
                wordRecord temp = sortingWords[i];
                sortingWords[i] = sortingWords[i + 1];
                sortingWords[i + 1] = temp;
            }
        }
    }
}

void printTenFromN(wordRecord distinctWords[], int N, int totalNumWords)
{
    cout << fixed << setprecision(5);
    wordRecord *tempboi = new wordRecord[10];
    int counter = 0;
    for (int i = N; i < N + 10; i++)
    {
        // cout << "i is: " << i << endl;
        tempboi[counter] = distinctWords[i];
        counter++;
    }

    sortAlphabetically(tempboi);

    for(int i = 0; i < 10; i++){
        cout << (double)tempboi[i].count / totalNumWords << " - " << tempboi[i].word << endl;
    }
    delete[] tempboi;
    tempboi = nullptr;
}
