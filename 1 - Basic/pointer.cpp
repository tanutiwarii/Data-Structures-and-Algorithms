#include <iostream>
using namespace std;

int main(){
    int a = 5;
    int* z = &a;
    int** b = &z;
    int*** c = &b;
    cout<<z<<endl;
    cout<<*z<<endl;
    cout<<b<<endl;
    cout<<*b<<endl;
    cout<<**b<<endl;
    cout<<***c<<endl;

    
}
