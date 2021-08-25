# include<stdio.h>
#include <iostream>
#include <fstream> 

int f(int x)
{
   printf("x is %d\n", x);
   return x;
}

int main()
{
    int i, j;
    for(i = 0; i < 4; i++){
        for(j = 0; j < 3; j++){
            if(i == 2){
                break;
            }
        }
    }
    std::cout << i;
}