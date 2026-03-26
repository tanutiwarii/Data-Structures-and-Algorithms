#include <iostream>
using namespace std;

void nNames(int i,int n, string str){         //pass parameters

    //base case
    if(i > n) return;                         //time complexity: O(N)
                                              //space complexity: O(N)
    //recursion
    cout<<str<<endl;;
    nNames(i+1,n,str);
    
}
int main(){
    int n;
    string name;
    cin>>n>>name;
    nNames(1,n,name);
}