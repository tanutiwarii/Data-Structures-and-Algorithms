//Frequency of the Most Frequent Element

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxFrequency(vector<int>& A, long k) {
    int i = 0, j;
    sort(A.begin(), A.end());
    long total = 0;
    for (j = 0; j < A.size(); ++j) {
        total += A[j];
        while ((long)A[j] * (j - i + 1) > total + k) {
            total -= A[i];
            i++;
        }
    }
    return j - i;
}

int main() {
    int n;
    long k;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cin >> k;

    cout << maxFrequency(nums, k) << endl;

    return 0;
}
