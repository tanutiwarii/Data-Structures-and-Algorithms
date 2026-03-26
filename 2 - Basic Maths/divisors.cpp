#include <iostream>
#include <vector>
using namespace std;

//brute force
void divisors(int n){
    for(int i = 1; i <=n;i++){                   //Time Complexity: O(n)
        if(n % i == 0){                          //Space Complexity: O(1)
            cout <<i<<endl;
        }
    }
}

//optimal approach
void oDivisors(int n){
    vector <int> ls;
    for(int i = 1; i*i <=n;i++){                       //Time Complexity: O(sqrt(n)logn)
        if(n % i == 0){                                //Space Complexity: O(sqrt(n))
            ls.push_back(i);
            if((n/i) !=i){
                ls.push_back(n/i);
            }
        }
    }
    sort(ls.begin(),ls.end());
    for(auto i : ls) cout<< i<<" "<<endl;
}

int main(){
    int n;
    cin>> n;
    oDivisors(n);

}