#include <iostream>
using namespace std;

void reverseArray(int arr[], int sz){
    int start = 0, end = sz-1;
    while(start < end) {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}
int main(){
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    reverseArray(arr, n);
    
    cout << "Reversed array: ";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}
