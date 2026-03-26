#include <iostream>
using namespace std;

int sumArray(int arr[], int n){
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum = sum + arr[i];
    }
    return sum;
}
int main(){
    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<< sumArray(arr, n)<<endl;
}