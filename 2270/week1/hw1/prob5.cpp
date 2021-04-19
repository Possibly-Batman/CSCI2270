#include <iostream>
#include <fstream>

using namespace std;

struct studentData
{
    string studentName;
    int homework;
    int recitation;
    int quiz;
    int exam;
    double average;
};

void addStudentData(studentData[], string, int, int, int, int, int);
int split(string, char, string[], int);
int GradeLetterToLowerBound(string);
int GradeLetterToUpperBound(string);
void printList(const studentData[], int);
char calcLetter(double);

int main(int argc, char* argv[]){
    int length = 0;
    studentData students[100];
    string arr[50];
    ifstream file;
    file.open(argv[1]);
    if(!file.is_open())
    {
        cout << "Failed to open the file." << endl;
        return(0);
    }
    string temp;
    while(getline(file,temp))
    {
        if(temp != "")
        {
            split(temp, ',', arr, 50); //stolen from 1300 woooo
            addStudentData(students, arr[0], stoi(arr[1]), stoi(arr[2]), stoi(arr[3]), stoi(arr[4]), length);
            length++;
        }

    }
    file.close();

    printList(students, length);
    ofstream file2;
    file2.open(argv[2]);

    for(int i = 0; i < length; i++)
    {
        double temp = students[i].average;
        if(temp >= GradeLetterToLowerBound(argv[3]) && temp <= GradeLetterToUpperBound(argv[4]))
        {
            file2 << students[i].studentName << "," << temp << "," << calcLetter(temp) << endl;
        } 

    }
    file2.close();
    return(0);
}

void addStudentData(studentData students[], string studNam, int hW, int rec, int qui, int exa, int len){ 
    studentData tempStruct;
    tempStruct.studentName = studNam;
    tempStruct.homework = hW;
    tempStruct.recitation = rec;
    tempStruct.quiz = qui;
    tempStruct.exam = exa;
    tempStruct.average = (hW + rec + qui + exa) / 4.0;
    students[len] = tempStruct;
}

char calcLetter(double avg)
{
    if(avg >= 90){
        return 'A';
    } else if(avg >= 80){
        return 'B';
    } else if(avg >= 70){
        return 'C';
    } else if(avg >= 60){
        return 'D';
    } else{
        return 'F';
    }
}

void printList(const studentData students[], int length){
    for(int i=0; i < length; i++){ //"<student_name> earned <student_average> which is a(n) <letter_grade>"
        cout << students[i].studentName << " earned " << students[i].average << " which is a(n) " << calcLetter(students[i].average) << endl;
    }
}

int GradeLetterToLowerBound(string given)
{
    char gradeLetter = given[0];
    if(gradeLetter == 'A'){
        return(90);
    } else if(gradeLetter == 'B'){
        return(80);
    } else if(gradeLetter == 'C'){
        return(70);
    } else if(gradeLetter == 'D'){
        return(60);
    } else {
        return(0);
    }
}
#include <cmath>
int GradeLetterToUpperBound(string given) // I think this is the best solution to this issue. Kinda gross they give you a string
{
    char gradeLetter = given[0];
    if(gradeLetter == 'A'){
        return(pow(2,12));
    } else if(gradeLetter == 'B'){
        return(90);
    } else if(gradeLetter == 'C'){
        return(80);
    } else if(gradeLetter == 'D'){
        return(70);
    } else {
        return(60);
    }
}

int split(string full,char delin,string repository[50],int len)
{
    int currentWord = 0;
    int words = 0;
    for(int i = 0; full[i]; i++)
    {
        if(full[i] == delin)
        {
            repository[words] = full.substr(0,i);
            full = full.substr(i+1,full.length()-i);
            i = 0;
            words++;
        }
    }
    if(full != "")
    {
        repository[words] = full;
        words++;
    }
    if(words>len)
    {
        return(-1);
    }
    return(words);
}