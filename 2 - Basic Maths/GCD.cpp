#include <iostream>
using namespace std;

//brute force
int  Gcd(int n, int x){
    int gcd = 1;
    for(int i = 1;i <= min(n,x);i++){
        if(n % i == 0 && x % i == 0) gcd = i;
    }
    return gcd;
}

//Euclidean Algorithm
int eGcd(int a, int b) {
    while(a > 0 && b > 0){
        if(a > b) a = a % b;
        else b = b % a;
    }
    if(a==0) return b;
    return a; 
}

//recurive approach using euclidean algorithm
int rGcd(int a, int b) {
    if (b == 0) return a;
    return rGcd(b, a % b);
}

int main(){
    int n,x;
    cin>>n>>x;
    cout<<eGcd(n,x)<<endl;

}