#include <iostream>
using namespace std;



//1-N
void nNames(int i,int n){         //pass parameters

    //base case
    if(i > n) return;             //time complexity: O(N)
                                  //space complexity: O(N)
    //recursion
    cout<<i<<endl;
    nNames(i+1,n);
    
}

//using backtracking for 1-N
void nBNames(int i,int n){         //pass parameters

    //base case
    if(i < 1) return;             //time complexity: O(N)
                                  //space complexity: O(N)
    //recursion
    nBNames(i-1,n);
    cout<<i<<endl;
    
}


//N-1
void nRNames(int i,int n){         //pass parameters

    //base case
    if(i < 1) return;             //time complexity: O(N)
                                  //space complexity: O(N)
    //recursion
    cout<<i<<endl;
    nRNames(i-1,n);
    
}

//using backtracking for N-1
void nBRevNames(int i,int n){         //pass parameters

    //base case
    if(i > n) return;             //time complexity: O(N)
                                  //space complexity: O(N)
    //recursion
    nBRevNames(i+1,n);
    cout<<i<<endl;
    
}

int main(){
    int n;
    cin>>n;
    nBRevNames(1,n);
}