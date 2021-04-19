struct studentData {
    string studentName;     
    int homework;     
    int recitation;     
    int quiz;
    int exam;     
    double ​average;
};
#include <iostream>

using namespace std;

void printList(const studentData students[], int length){
    for(int i=0; i < length; i++){ //"<student_name> earned <student_average> which is a(n) <letter_grade>"
        cout << students[i].studentName << " earned " << students[i].​average << " which is a(n) " << calcLetter(students[i].​average) << endl;
    }
}