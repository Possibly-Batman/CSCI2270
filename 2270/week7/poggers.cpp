#include <iostream>
using namespace std;
int myFunc(int n){
    int result = 0;
    if(n <= 0){
        return 0;
    }
    if(n == 1){
        return 1;
    }
    result = myFunc(n-1) + myFunc(n-3);
    return result;
}

int main(){
    cout << myFunc(4);
    return 0;
}

// using namespace std;
// void fun (int n) { 
//     if(n > 0){
//         fun(n-1);
//         printf("%d", n);
//         fun(n-1);
//     }
//     else return;
// }
// int main(){
//     fun(3);
//     return 0;
// }