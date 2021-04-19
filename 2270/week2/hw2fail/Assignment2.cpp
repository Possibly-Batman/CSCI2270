#include <iostream>
#include <fstream>

#include "DynamicallyDoublingArray.h"

using namespace std;

// this is reference for reading a file word by word  (Can be used for reading both stop words and unique words)
int main(int argc, char const *argv[])
{
    int N = stoi(argv[1]);
    string analyziedFile = argv[2];
    string ignoredWordsFile = argv[3];
    
    DynamicallyDoublingArray MobyArray = DynamicallyDoublingArray(ignoredWordsFile);

    ifstream inStream;       // stream for reading in file
    inStream.open(analyziedFile); // open the file

    string word;

    while (inStream >> word)
    {
        MobyArray.add(word);
    }


    cout << "Array doubled: " << MobyArray.getNumberTimesDoubled() << endl;
    cout << "Distinct non-common words: " << MobyArray.getSize() << endl;
    cout << "Total non-common words: " << MobyArray.getTotalOccurrences() << endl;
    MobyArray.~DynamicallyDoublingArray();
    inStream.close(); // close the file
    return 0;
}
