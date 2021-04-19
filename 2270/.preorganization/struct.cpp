#include <iostream>
using namespace std;

int factorial(int a){
    if(a == 1){
        return 1;
    }
    return a * factorial(a-1);
}

int main(){
    struct Person{
        string first;
        string last;
        double number;
    };
    Person a = {"pog", "gers", 300};
    a.last = "Gers";

    Person* pa = &a;

    cout << "factorial of 4 is: " << factorial(4) << endl;

    cout << (*pa).first << endl;//these lines mean exactly the same thing
    cout << pa->first << endl;//these lines mean exactly the same thing

    cout << a.first << endl;
    cout << a.last << endl;
    return 0;
}