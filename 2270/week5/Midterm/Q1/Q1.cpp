/*
CSCI 2270 - Spring 2021
Midterm 1
Question 1 starter code.

*/


#include <iostream>

using namespace std;

/*
    * TODO your function header goes here
*/
void trim(int*&, int, int);


void testPrint(int *p0, int length);

int main(){
   
    int a_test[] = {3, 2, 5, 1, 0, 8, 4};
    int test_length = 7;
   
   
    /*
    Test 1
    */
    cout << "\n---------------------\n";
    
    int * a0 = new int[test_length];
    for(int i = 0; i<test_length; i++){
        a0[i] = a_test[i];
    }

    int target = 0; 
    
    /*
        * TODO your function call goes here. It should look like:
       
    */ 
   
    trim(a0, test_length, target); //woah it is the same crazy

    cout << "Test 1: \n"  << "expected >> 3 2 5 1 " << endl;
    testPrint(a0, 4); //Why was the length in this set to a static veriable that doesn't change. 
    delete [] a0;

    return 0;
}




/*
    * TODO your function definition goes here
*/
void trim(int* &array, int length, int target){
    int targetIndex = -1;
    for(int i = 0; i < length; i++){ //iterate through array to find the index of target
        if(array[i] == target){
            targetIndex = i;
            i = length;
        }
    }

    if(targetIndex == -1){
        return; //Don't think this edge case is explicitly needed, included regardless
    }
    
    int* replacementArray = new int[targetIndex]; //create another smaller array to eventually free the space taken up by targets

    for(int i = 0; i < targetIndex; i++){
        replacementArray[i] = array[i];
    }

    int* temp = array;
    array = replacementArray; 
    
    delete[] temp; // free that memory woooo
    temp = nullptr;
}


void testPrint(int *p0, int length){
    
    cout << "result   >> ";

    for(int i = 0; i<length; i++){
        cout << p0[i] << " ";
    }
    cout << "\n---------------------\n\n" << endl;
}