#include <iostream>
using namespace std;

struct myStruct{

    int size;

    float weight;


};

int main(){
    int a = 12;
    int b = 33;
    int *pa = &a;
    int *pb = &b;
    *pb = *pa + *pb;
    cout << a << "," << *pb << endl;
}