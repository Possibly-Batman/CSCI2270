#include <iostream>

using namespace std;

int main(){
    // string[] *arr = string[20];

    append()
}

bool append(string* &str_arr, string s, int &numEntries, int &arraySize)
{
    //TODO: Complete this function
    if(arraySize == numEntries){
        string *replacementArray = new string[arraySize*2];
        arraySize = arraySize * 2;
        for(int i = 0; i < numEntries; i++){
            replacementArray[i] = str_arr[i];
        }

        delete[] str_arr;
        str_arr = replacementArray;

        str_arr[numEntries] = s;
        numEntries++;
        return true;
    }

    str_arr[numEntries] = s;
    numEntries++;
    return false;
}