/****************************************************************/
/*                Job Queue Driver File                 */
/****************************************************************/
/* TODO: Implement menu options as described in the writeup     */
/****************************************************************/

#include "JobQueue.hpp"
#include <iostream>
#include <cmath>
#include <iomanip>
// you may include more libraries as needed

using namespace std;

/*
 * Purpose: displays a menu with options
 * @param none
 * @return none
 */
void menu()
{
	cout << "*----------------------------------------*" << endl;
	cout << "Choose an option:" << endl;
    cout << "1. Add jobs into the queue" << endl;
	cout << "2. Dispatch jobs from the queue" << endl;
	cout << "3. Return the queue size and exit" << endl;
	cout << "*----------------------------------------*" << endl;
}
// Use getline for reading
int main(int argc, char const *argv[])
{

	JobQueue Qboi;

	// string for input
	string input;
	
	while(true)
	{
		menu();
		getline(cin, input);

		if(stoi(input) == 1){
			cout << "Enter the number of jobs to be created:" << endl;
			getline(cin, input);

			int numInput = stoi(input);
			
			for(int i = 0; i < numInput; i++){
				cout << "job" << i + 1 << ":" << endl;
				getline(cin, input);

				Qboi.enqueue(input);
			}
		}
		else if(stoi(input) == 2){
			cout << "Enter the number of jobs to be dispatched:" << endl;
			getline(cin, input);

			int numSlaughter = stoi(input);
			
			for(int i = 0; i < numSlaughter; i++){
				if(!Qboi.isEmpty()){

					cout << "Dispatched: " << Qboi.peek() << endl;

					Qboi.dequeue();
				}
				else{
					cout << "No more jobs to be dispatched from queue" << endl;
					break;
				}
			}
		}
		else if(stoi(input) == 3){
			cout << "Number of jobs in the queue:" << Qboi.queueSize() << endl;
			return 0;
		}
		else {
			return -1;
		}
	}
}
