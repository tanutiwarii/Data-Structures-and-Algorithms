#include <iostream>
using namespace std;
int main(){
    int arr[] = {15, 3, 8, -94, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    int smallest = INT_MAX;
    for(int i = 0; i < n; i++){
        if(arr[i] < smallest){
            smallest = arr[i];
            
        }
    }
    cout << "Smallest element is: " << smallest << endl;
    return 0;
}
