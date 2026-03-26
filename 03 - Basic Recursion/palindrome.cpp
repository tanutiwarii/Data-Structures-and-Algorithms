#include <iostream>
using namespace std;

bool isPalindrome(string &s, int i, int n) {
    if (i >= n / 2) return true;
    if (s[i] != s[n - i - 1]) return false;
    return isPalindrome(s, i + 1, n);
}

int main() {
    string s;
    cin >> s;

    if (isPalindrome(s, 0, s.length())) {
        cout << "Palindrome" << endl;
    } else {
        cout << "Not a palindrome" << endl;
    }

    return 0;
}
