#include <iostream>

using namespace std;


int main() {
  int m=1, n=2;
  int *p=&m, *q=&n;
  int *r;
  r=p;
  p=q;
  q=r;
  cout<<m<<","<<n<<","<<*p<<","<<*q<<endl;
  return 0;
}

