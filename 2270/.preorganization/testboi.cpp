#include <iostream>

void doSomething( int *x, int *y);
void doSomething( int x, int y);
void doSomething(int& x, int y);
void doSomething( int& x, int& y);


int main(int argc, char *argv[]){

    std :: cout << argc << std :: endl ;

    return 0;

}