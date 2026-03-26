#include <iostream>
using namespace std;

//brute force
void primeNo(int n){
    int cnt = 0;                                //Time Complexity: O(n)
    for(int i = 1; i<=n; i++){                  //Space Complexity: O(1)
        if(n%i ==0){
            cnt++;
        }  
    }
    if(cnt > 2){
        cout<<n<<" is not a prime no,"<<endl;
    }else{
       cout<<n<<" is a prime no,"<<endl;
    }
}

//optimized approach
void oPrimeNo(int n){
    int cnt = 0;                                //Time Complexity: O(sqrt(n)logn)
    for(int i = 1; i*i<=n; i++){                //Space Complexity: O(1)
        if(n%i ==0){
            cnt++;
            if((n/i) != i) cnt++;
        }  
    }
    if(cnt > 2){
        cout<<n<<" is not a prime no,"<<endl;
    }else{
       cout<<n<<" is a prime no,"<<endl;
    }
}
int main(){
    int n;
    cin>>n;
    oPrimeNo(n);
}