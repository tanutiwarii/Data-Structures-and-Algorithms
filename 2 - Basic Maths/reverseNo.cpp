#include <iostream>
using namespace std;

int reverseNo(int n){
    int revNo = 0;
        while(n){
            if (revNo>INT_MAX/10 || revNo<INT_MIN/10) return 0;    //[-231, 231 - 1]
            revNo = (revNo * 10) + n%10;                           //time complexity - O(Log10∣n∣)
            n = n/10;                                              //space complexity - O(1)
        }
        return revNo;
    }

int main(){
    int n;
    cin>>n;
    int reversed = reverseNo(n);
    cout << reversed << endl; 
}