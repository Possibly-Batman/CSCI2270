#include <iostream>

using namespace std;

void Swap(int& x, int y);

void CalculateCost(int count, float& subTotal, float& taxCost){

    if(count<10){

        subTotal = count * 0.50;

    }

    else{

        subTotal = count * 0.20;

    }

    taxCost = 0.1 * subTotal;
}

int* foo(int x){
    int *y = new int[x*x];
    return y;
}

int main(void){
    // int a = 1; 
    // int b = 2;
    // Swap(a,b);
    // cout << a << ", " << b << endl;
    // float distance = 17.9;
    // // float*amt  =distance;
    // // float &amt = *distance;
    // // float*amt = *distance;
    // float*amt = &distance;
    // cout << amt << "pog" << distance << endl;
    // int a[3] = {1,2,3};
    
    // // cout << *a[1] << endl;
    // // cout << &a[1] << endl;
    // // cout << &(a + 1) << endl;
    // cout << *(a + 1) << endl;
    // cout << *a + 1 << endl;
    // cout << a[1] << endl;
    // // cout << &a + 1 << endl;

    // int a=5, b=10;
    // int *pa=&a, *pb = &b;
    // // let pa point to b
    // pa = pb; 
    // cout << *pa << "pog" << *pb << endl;
    // return 0; 

    // int m = 1, n = 2;
    // int *pm = &m, *pn = &n, *r;
    // r = pn;
    // pn = pm;
    // *pm = *pn+2;
    // cout << m << ", " << n << ", " << *r << ", " << *pm << endl;

    // float tax = 0.0, subTotal = 0.0;

    // CalculateCost(15,subTotal,tax);

    // cout<<"The cost for 15 items is"<<subTotal<<", and the tax for"<<subTotal<<"is"<<tax<<endl;

    // return 0;

    int * z = foo(10);
    //free space
    delete[] z;
    return 0;

    return 0;
}
void Swap(int& x, int y){
    int temp = x;
    x = y;
    y = temp;
}