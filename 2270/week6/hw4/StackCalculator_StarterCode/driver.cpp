#include<iostream>
#include<cmath>
#include<iomanip>
#include "StackCalculator.hpp"

using namespace std;



int main()
{
  // stack to hold the operands
  StackCalculator stack;

  int numElement = 0;
  string* inparr = new string[50];

  // enter a number
  string number;
  cout << "Enter the operators and operands ('+', '*') in a prefix format" << endl;

  while(true)
  {
    cout << "#> ";
    getline(cin, number);
    
    if(number.at(0) == '='){
      break;
    } else{
      inparr[numElement] = number;
      numElement++;
    }

    /* TODO
       1. Read input (operators and operands) until you encounter a "="
       2. store them in inparr
    */

  }


  if(numElement == 0){
    cout << "No operands: Nothing to evaluate" << endl;
  }
  else{
    if(stack.evaluate(inparr, numElement)){
      cout << "Result= " << stack.peek()->number << endl;
      stack.pop();
    }
  }

  /* TODO - If the inparr is empty then print "No operands: Nothing to evaluate"
            else call the evaluate function
  */

  /* TODO - Validate the expression
      1. If valid then print the result cout << "Result= "<<result << endl;
      2. Else, print "Invalid expression"*/
 
  return 0;
}
