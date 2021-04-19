#include <iostream>
#include <string>
using namespace std;

// any file that uses the SLL class must include this header file
#include "SLL.hpp"

int main(){
   
	/*
	Test cases are provided only to help you test your code. Each
	submission will be individually inspected by the teaching staff.

	*/

    /*
    Test 1
    */
    cout << "\n---------------------\n";
	int n = 5;
	char testStringA[] = {'m','a','d','a','m'};
	SLL sA;
	for(int i = 0; i<n; i++){
		sA.insert(nullptr,testStringA[i]);
	}
	cout << "Test A:" << endl; 
	sA.displayList();

	cout << "expected >> Palindrome " << endl;

	if(sA.palindrome())
		cout << "result   >> Palindrome" << endl;
	else
		cout << "result   >> Not a palindrome" << endl;
	    cout << "\n---------------------\n";

	/*
    Test 2
    */
    cout << "\n---------------------\n";
	char testStringB[] = {'m','a','d','m','a'};
	SLL sB;
	for(int i = 0; i<n; i++){
		sB.insert(nullptr,testStringB[i]);
	}
	cout << "Test B: \n";
	sB.displayList();
	cout << "expected >> Not a palindrome " << endl;
	if(sB.palindrome())
		cout << "result   >> Palindrome" << endl;
	else
		cout << "result   >> Not a palindrome" << endl;
    cout << "\n---------------------\n";

	/*
    Test 3
    */
    cout << "\n---------------------\n";
	char testStringC[] = {'p'};
	n = 1;
	SLL sC;
	for(int i = 0; i<n; i++){
		sC.insert(nullptr,testStringC[i]);
	}
	cout << "Test C: \n";
	sC.displayList();
	cout << "expected >> Palindrome " << endl;
	if(sC.palindrome())
		cout << "result   >> Palindrome" << endl;
	else
		cout << "result   >> Not a palindrome" << endl;
    cout << "\n---------------------\n";

	/*
    Test 4
    */
    cout << "\n---------------------\n";
	char testStringD[] = {'p','p','l','l','p','p'};
	n=6;
	SLL sD;
	for(int i = 0; i<n; i++){
		sD.insert(nullptr,testStringD[i]);
	}
	cout << "Test D: \n";
	sD.displayList();
	cout << "expected >> Palindrome " << endl;
	if(sD.palindrome())
		cout << "result   >> Palindrome" << endl;
	else
		cout << "result   >> Not a palindrome" << endl;
    cout << "\n---------------------\n";

	/*
    Test 5
    */
    cout << "\n---------------------\n";
	char testStringE[] = {};
	n=0;
	SLL sE;
	for(int i = 0; i<n; i++){
		sE.insert(nullptr,testStringE[i]);
	}
	cout << "Test E: \n";
	sE.displayList();
	cout << "expected >> Palindrome " << endl;
	if(sE.palindrome())
		cout << "result   >> Palindrome" << endl;
	else
		cout << "result   >> Not a palindrome" << endl;
    cout << "\n---------------------\n";

	//you guys never deleted the memory taken up by these things. I'm not gonna do it.

	return 0;
}
