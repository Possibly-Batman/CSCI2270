#include <iostream>
#include <fstream>

using namespace std;

int addToArrayAsc(float sortedArray[100], int numElements, float newValue);

int main(int argc, char* argv[]){
    ifstream file;
    file.open(argv[1]);

    if(!file.is_open()){
        cout << "Failed to open the file." << endl;
        return(0);
    }

    float arr[100];
    int counter = 0;
    string readLine;
    
    while(getline(file, readLine)){
        if(readLine != ""){
            counter = addToArrayAsc(arr, counter, stof(readLine));
            for(int i = 0; i < counter; i++){
                if(i > 0){
                    cout << ",";
                }
                cout << arr[i];
            }
            cout << endl;
        }
    }
    return(0);
}

int addToArrayAsc(float sortedArray[100], int numElements, float newValue){
    sortedArray[numElements] = newValue; 
    numElements++;
    for(int i = 0; i < numElements-1; i++){
        for(int j = 0; j < numElements-i-1; j++){
            if(sortedArray[j] > sortedArray[j+1]){
                float tempVar = sortedArray[j];
                sortedArray[j] = sortedArray[j+1];
                sortedArray[j+1] = tempVar;
            }
        }
    }
    return(numElements);
}