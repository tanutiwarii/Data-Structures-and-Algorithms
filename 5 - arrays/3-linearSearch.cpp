#include <iostream>
using namespace std;

int main() {
    int arr[] = {15, 3, 8, -94, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 9;

    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            cout << i << endl;
            return 0;
        }
    }

    cout << -1 << endl;  // print result
    return 0;
}
