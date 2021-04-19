#include "List.h"
#include <iostream>


using namespace std;

int main()
{
    List ll;
    Node nn;
    nn.name = "poggers";
    nn.phone = 786844689;
    ll.insert(nn);
    nn.name = "Jackers boi";
    nn.phone = 3040343;
    ll.insert(nn);

    for(int i = 0; i < 2; i++){
        if(ll.search("Taylor") != -1){
            cout << "taylor's been found" << endl;
        } else{
            cout << "birthing Taylor" << endl;
            nn.name = "Taylor";
            nn.phone = 2367737;
            ll.insert(nn);
        }
    }

    cout << "taylor is being exterminated" << endl;
    ll.remove(ll.search("Taylor"));

    ll.traverse();
    return 0;
}