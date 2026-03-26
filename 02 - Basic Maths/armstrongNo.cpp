#include <iostream>
#include <cmath>
using namespace std;

bool armstrongNo(int n) {
    int original = n;
    int sum = 0;
    int digits = 0;

    int temp = n;
    while (temp > 0) {                    //Time Complexity: O(log n)
        digits++;                         //Space Complexity: O(1)
        temp /= 10;
    }

    temp = n;
    while (temp > 0) {
        int digit = temp % 10;
        sum += pow(digit, digits);  
        temp /= 10;
    }

    return (sum == original);
}

int main() {
    int n;
    cin >> n;

    if (armstrongNo(n))
        cout << "true" << endl;
    else
        cout << "false" << endl;
}
