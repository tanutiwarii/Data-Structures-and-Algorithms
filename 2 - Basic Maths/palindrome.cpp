#include <iostream>
#include <climits>
using namespace std;

bool isPalindrome(int n) {
    int revNo = 0;
    int dup = n;

    while (n>0) {
        if (revNo > INT_MAX / 10 || revNo < INT_MIN / 10)           //time complexity: O(log10(n))
            return false;                                           //Space Complexity: O(1)
        revNo = revNo * 10 + n % 10;
        n = n / 10;
    }

    return (dup == revNo);
}

int main() {
    int n;
    cin >> n;

    if (isPalindrome(n))
        cout << "true" << endl;
    else
        cout << "false" << endl;
}
