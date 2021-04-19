#include <iostream>
using namespace std;
struct studentData {
    string studentName;     
    int homework;     
    int recitation;     
    int quiz;
    int exam;     
    double ​average;
};
void addStudentData(studentData students[], string studNam, int hW, int rec, int qui, int exa, int len){ 
    studentData tempStruct;
    tempStruct.studentName = studNam;
    tempStruct.homework = hW;
    tempStruct.recitation = rec;
    tempStruct.quiz = qui;
    tempStruct.exam = exa;
    tempStruct.​average = (hW + rec + qui + exa) / 4.0;
    students[len] = tempStruct;
}
int main(){
    cout << "poggers" << endl;
}