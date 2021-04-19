#include <iostream>
#include "StackCalculator.hpp"


using namespace std;
/*
 * Purpose: Determine whether some user input string is a
 *          valid floating point number
 * @param none
 * @return true if the string s is a number
 */
bool isNumber(string s)
{
    if(s.size() == 1 && s == "-")
      return false;

    else if(s.size() > 1 && s[0] == '-')
      s = s.substr(1);

    bool point = false;
    for(int i = 0; i < s.size(); i++){
      if(!isdigit(s[i]) && s[i] != '.')
        return false;
      if(s[i]=='.' and !point) point = true;
      else if(s[i]=='.' and point) return false;
    }

    return true;
}

StackCalculator::StackCalculator()
{
  stackHead = NULL;
}

StackCalculator::~StackCalculator()
{
  Operand* current = stackHead;
  while(current != NULL){
    Operand* temp = current->next;
    delete current;
    current = temp;
  }
  stackHead = NULL;
}

bool StackCalculator::isEmpty()
{
	if(stackHead == NULL){
    return true;
  }
  return false;
}

void StackCalculator::push(float number)
{
  Operand* insert = new Operand();
  insert->next = stackHead;
  insert->number = number;
  stackHead = insert;
}

void StackCalculator::pop()
{
  if(stackHead == NULL){
    cout << "Stack empty, cannot pop an item." << endl;
    return;
  }
  Operand* temp = stackHead;
  stackHead = stackHead->next;
  delete temp;
  temp = nullptr;
}

Operand* StackCalculator::peek()
{
	if(stackHead == NULL){
    cout << "Stack empty, cannot peek." << endl;
  }
  return stackHead;
}

bool StackCalculator:: evaluate(string* s, int size)
{
  for(int i = size - 1; i >= 0; i--){
    if(isNumber(s[i])){
      push(stof(s[i]));
    }
    else if(s[i].at(0) == '+'){
      
      if(stackHead == NULL || stackHead->next == NULL){
        cout << "err: not enough operands" << endl;
        return false;
      }

      float firstnum = peek()->number;
      pop();
      float secondnum = peek()->number;
      pop();
      push(firstnum + secondnum);
      
    }
    else if(s[i].at(0) == '*'){
      
      if(stackHead == NULL || stackHead->next == NULL){
        cout << "err: not enough operands" << endl;
        return false;
      }
      
      float firstnum = peek()->number;
      pop();
      float secondnum = peek()->number;
      pop();
      push(firstnum * secondnum);
      
    }
    else{
      cout << "err: invalid operation" << endl;
      return false;
    }
  }
  // cout << "Result= " << peek() << endl;
  // pop();
    /*TODO: 1.scan the array from the end
            2.Use isNumber function to check if the input is an operand
            3.push all operands to the stack
            4.If operator take two element of from the stack,
              compute and put the result back in stack
            5.Handle the boundery cases as required.
            6.Read the writeup for more details
    */
		return true;
}
