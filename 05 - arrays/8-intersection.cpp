#include <iostream>
#include <unordered_set>
using namespace std;

int sortedIntersectionArray(int arr1[], int n, int arr2[], int m, int result[]) {
    int i = 0, j = 0, k = 0;

    while (i < n && j < m) {
        if (arr1[i] == arr2[j]) {
            result[k++] = arr1[i];
            i++;j++;
        }
        else if (arr1[i] < arr2[j]) {
            i++;
        }
        else {
            j++;
        }
    }
    return k; 
}

int unsortedIntersectionArray(int arr1[], int n, int arr2[], int m, int result[]) {
    unordered_set<int> s;
    int k = 0;

    for(int i = 0; i < n; i++)
        s.insert(arr1[i]);

    for(int j = 0; j < m; j++){
        if(s.find(arr2[j]) != s.end()){
            result[k++] = arr2[j];
            s.erase(arr2[j]); 
        }
    }
    return k;
}
int main() {
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {2, 4, 6, 8, 10};


    int arr3[] = {13,12,14,15,11};
    int arr4[] = {15,16,12,14,11,17,19,1};

    int n = sizeof(arr1) / sizeof(arr1[0]);
    int m = sizeof(arr2) / sizeof(arr2[0]);
    int result1[min(n, m)];

    int o = sizeof(arr3) / sizeof(arr3[0]);
    int p = sizeof(arr4) / sizeof(arr4[0]);
    int result2[min(o, p)];


    int size1 = sortedIntersectionArray(arr1, n, arr2, m, result1);
    int size2 = unsortedIntersectionArray(arr3, o, arr4, p, result2);

    for (int i = 0; i < size1; i++) {
        cout << result1[i] << " ";
    }
    cout<<endl;

     for (int i = 0; i < size2; i++) {
        cout << result2[i] << " ";
    }
    cout<<endl;
    return 0;
}
