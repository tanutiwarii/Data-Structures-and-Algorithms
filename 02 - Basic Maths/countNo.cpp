#include <iostream>
using namespace std;

//using division
int count(int n){
    int cnt = 0;
    while(n>0){                //time complexity - O(log10(n))
        cnt = cnt+1;           //space complexity - O(1)
        n = n/10;
    }
    return cnt;
}

//using log
int logCount(int n){
    int cnt = log10(n) + 1;
    return cnt;
}

int main(){
    int n;
    cin>>n;
    cout<<logCount(n)<<endl;
}