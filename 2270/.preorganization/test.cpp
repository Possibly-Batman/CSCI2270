//try compiling and doing './a.out arg2 arg 3 arg 4 '

#include <iostream>
int main (int argc, char const *argv[]){
    std::cout << "Total Arguments: "<< argc << std::endl;

    std:: cout << "---------------" << std::endl;

    for (int i = 0; i < argc; i++){
        std:: cout << "Argument #" << i + 1 << ": ";
        std :: cout << argv[i] << std::endl;
    }
}