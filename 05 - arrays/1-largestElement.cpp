#include <iostream>
using namespace std;

int main(){
    int arr[] = {25, 100, 2, 43, 78};
    int n = sizeof(arr)/sizeof(arr[0]);
    int largest = INT_MIN;
    for(int i = 0; i < n; i++){
        if(arr[i] > largest){
            largest = arr[i];
        }
    }
    cout << "Largest element is: " << largest << endl;
    return 0;
}