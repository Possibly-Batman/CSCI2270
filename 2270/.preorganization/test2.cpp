#include <iostream>

int main(){
    int x = 1000;

    enum poggers_enum_type {A, B, C, D};

    poggers_enum_type y = B; // poggers_enum_type can only be A B C or D

    // poggers_enum_type y = (poggers_enum_type) 2; // poggers_enum_type can only be A B C or D

    std::cout << sizeof(x) << std::endl;
    std::cout << sizeof(y) << std::endl;

// & symbol says you're looking for the address

    std::cout << "address of x: " << &x << std::endl;

    int* px; //px stores the address of an integer
    px = &x;

    return 0;
}