#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <unordered_set>
#include <map>
using namespace std;

//pairs
void explainPair(){

    pair <int, int> p ={1,3};
    cout <<p.first <<" "<<p.second<<endl; //1 3

    pair<int, pair <int, int>> r ={2,{1,3}};
    cout <<r.first<<endl; //2
    cout <<r.second.first<<endl; //1
    cout <<r.second.second<<endl; //3

    pair <int, int> arr[] ={{4,6}, {8,3}, {0,5}};
    cout <<arr[2].second<<endl; //5
}

void explainVector(){
    vector <int> vec;

    vec.push_back(1);                            // {1}
    vec.emplace_back(2);                         // {1, 2} emplace_back is faster than push_back

    vector <pair<int, int>>v;
    v.push_back({1,3});                         //{1,3}
    v.emplace_back(2,9);                        //{{1, 3}, {2,9}}

    
    cout<<vec[1]<<endl;                        //2 from {1,2}
    cout<<vec.at(1)<<endl;                     //2 from {1,2} 

    cout<<vec.size();                          //2
    vec.pop_back();                            //1

    vector <int> ::iterator i = vec.begin();   //iterator which point to the first elements's memory and not on the element

    cout<<*(i)<<" "<<endl;                     //1 from {1, 2} using pointer
    
    i++;
    cout<<*(i)<<" "<<endl;                     //2 from {1, 2} using pointer

    i++;
    cout<<*(i)<<" "<<endl;                     //0 since no further elements so returns garbage value

    vector <int> ::iterator e = vec.end();     //iterator which point to the last elements's memory and not on the element

    cout<<vec.back()<<endl;                     //2 from {1,2} since it is the last element


    for(vector <int> ::iterator i = vec.begin(); i != vec.end();i++){  //using for loop to print elements
        cout<<*(i)<<" "<<endl;                  //1 from {1, 2} using pointer
    }

    for(auto i = vec.begin(); i != vec.end();i++){  //auto automatically assigns the data type
        cout<<*(i)<<" "<<endl;                  //1 from {1, 2} using pointer
    }

    for(auto i : vec){                          //for each loop
        cout<<(i)<<" "<<endl;                   //1 from {1, 2} using pointer
    }

    //{10, 20, 30, 40, 50}
    vec.erase(vec.begin()+1);                   //{10, 30, 40, 50}
    vec.erase(vec.begin()+2,vec.begin()+4);     //{10, 20, 50}    [start,end)

    vector <int> v2(3, 100);                    //{100, 100, 100}

    vector <int> v3(5);                         //{0, 0, 0, 0, 0}   
    
    vector <int> v1(v2);                        //copy of v2 will get stored in v1.
    
    v2.insert(v2.begin(), 300);                 //{300, 100, 100, 100}
    v2.insert(v2.begin()+1, 2, 10);             //{300, 10,10, 100, 100, 100}

    vector<int> copy(2,50);                     //{50, 50}  
    v2.insert(v2.begin(), copy.begin(),copy.end());    //{50, 50, 300, 10,10, 100, 100, 100}

    //v1 = {10,20}
    //v2 = {30,40}
    v1.swap(v2);                                //v1 = {30,40}   v2 = {10,20}

    v1.clear();                                 //erase entire vector
    cout<< v1.empty();                          //gives true or false
}

void explainList(){
    
    list<int> ls;
    ls.push_back(4);      //{4}
    ls.emplace_back(5);   //{4, 5}
    ls.push_front(3);     //{3, 4, 5}
    ls.emplace_front(2);  //{2, 3, 4, 5}
    //similar functions as vector
}

void explainDeque(){
    deque<int> dq;
    dq.push_back(4);      //{4}
    dq.emplace_back(5);   //{4, 5}
    dq.push_front(3);     //{3, 4, 5}
    dq.emplace_front(2);  //{2, 3, 4, 5}
    //similar functions as vector and lists
}

void explainStack(){

    stack<int> st;  //LIFO
    st.push(1);     //{1}
    st.push(2);     //{2, 1}
    st.push(3);     //{3, 2, 1}
    st.push(1);     //{1, 3, 2, 1}
    st.emplace(3);  //{3, 1, 3, 2, 1}
    
    st.pop();       //{1, 3, 2, 1}
    st.top();       //1
    st.size();      //4
}

void explainQueue(){
    
    queue <int> q;            //FIFO
    q.push(1);                //{1}
    q.push(2);                //{1, 2}
    q.push(3);                //{1, 2, 3}
    q.push(1);                //{1, 2, 3, 1}
    q.emplace(3);             //{1, 2, 3, 1, 3}

    q.back() +=4;             //{1, 2, 3, 1, 7}
    cout<<q.front()<<endl;    //{1}
    cout<<q.back()<<endl;     //{7}

    q.pop();                  //{2, 3, 1, 3}
    cout<<q.front()<<endl;    //{2}
}

void explainPQ(){
    priority_queue <int> pq;
    pq.push(10);                //{10}
    pq.push(20);                //{20, 10}
    pq.push(5);                 //{20, 10, 5}
    pq.emplace(13);             //{20, 13, 10, 5}

    cout<<pq.top()<<endl;       //{20}
    pq.pop();                   //{13, 10, 5}
    cout<<pq.top()<<endl;       //{13}

    //minimum heap
    priority_queue <int, vector<int>, greater<int>> pq1;
    pq1.push(10);                //{10}
    pq1.push(20);                //{10, 20}
    pq1.push(5);                 //{5, 10, 20}
    pq1.emplace(13);             //{5, 10, 13, 20}

    cout<<pq1.top()<<endl;       //{5}
    pq1.pop();                   //{10, 13, 20}
    cout<<pq1.top()<<endl;       //{10}

}

void explainSet(){

    set<int>st;          //unique, sorted order
    st.insert(1);        //{1}
    st.insert(2);        //{1,2}
    st.insert(2);        //{1,2}
    st.emplace(4);       //{1,2,4}
    st.insert(3);        //{1,2,3,4}      

    auto i1 = st.find(3); // returns iterator to element 3
    auto i2 = st.find(6); // returns st.end() since not found

    st.erase(5);         // takes logarithmic time

    int cont = st.count(1);
    auto i3 = st.find(3);
    st.erase(i3);         // takes constant time

    //{1, 2, 3, 4, 5}
    auto i4 = st.find(1);
    auto i5 = st.find(2);
    st.erase(i1, i2);    //after erase {1, 4, 5} [first, last)

    //{1, 2, 3, 4, 5}
    auto it6 = st.lower_bound(2); //2 as the first element ≥ 2 is 2
    auto it7 = st.upper_bound(3); //4 as the first element > 3 is 4
}

void explainMultiSet(){

    //everything is same as set
    //only change is that it can store duplicates also

    multiset<int>ms;          // sorted order
    ms.insert(1);             //{1}
    ms.insert(2);             //{1,2}
    ms.insert(2);             //{1,2,2}
    ms.emplace(4);            //{1,2,2,4}
    ms.insert(3);             //{1,2,2,3,4} 

    int cnt = ms.count(2);    //counts no of occurences

    for(auto i : ms){
        cout <<i;             // {1, 2, 2, 3, 4}
    }
    cout<<endl;

    ms.erase(ms.find(2));      //only single 2 removed, output = {1,2,3,4}
    ms.erase(ms.find(2), next(ms.find(2)));   // output ={1,3,4}

    for(auto i : ms){
        cout <<i;              // {1, 3, 4}
    }
    cout<<endl;

    //rest all functions are same as sets.
}

void explainUset(){
    unordered_set <int> uo;
    
    //unique, but unsorted
    //all operations and functions are same
    //but lower_bound and upper_bound does not work


}

void explainMap(){

    //stores unique 'keys' in sorted order
    map <int, int> mpp;                   //<key, value>
    map <int, pair<int, int>> mpp1;       //<key, 2 values>
    map <pair<int, int>, int> mpp2;       //<2 keys, value>

    //multiple ways of storing key-value pair in map
    mpp[1] = 2;
    mpp.insert({4,5});
    mpp.emplace(6,7);
    mpp.insert({2,5});

    for(auto i : mpp){
        cout << "{"<<i.first << " " <<i.second<<"}";   //{1 2}{2 5}{4 5}{6 7}        
    }
    cout<<endl;

    mpp1 [10] = {11, 12};
    for(auto i : mpp1){
        cout <<"{"<< i.first << "," <<i.second.first<<" "<<i.second.second<<"}";   //{10,11 12}          
    }
    cout<<endl;

    mpp2 [{14,15}] = 11;
    for(auto i : mpp2){
        cout <<"{"<< i.first.first << " " <<i.first.second<<","<<i.second<<"}";   //{14 15,11}          
    }
    cout<<endl;

    //{1 2}{2 5}{4 5}{6 7} 
    cout<<mpp[1]<<endl;   //2
    cout<<mpp[5]<<endl;   //0, since does not exist

    auto i = mpp.find(1);
    cout<<i->second<<endl;


    auto i1 = mpp.lower_bound(2);
    if (i1 != mpp.end()) {
        cout << "Key: " << i1->first << ", Value: " << i1->second << endl;  //Key: 2, Value: 5
    } else {
        cout << "No element ≥ 2 found" << endl;
    }

    auto i2 = mpp.lower_bound(9);
    if (i2 != mpp.end()) {
        cout << "Key: " << i2->first << ", Value: " << i2->second << endl;  
    } else {
        cout << "No element ≥ 9 found" << endl;  //No element ≥ 9 found
    }

    auto i3 = mpp.upper_bound(3);
    if (i3 != mpp.end()) {
        cout << "Key: " << i3->first << ", Value: " << i3->second << endl;  //Key: 4, Value: 5
    } else {
        cout << "No element < 3 found" << endl;
    }
}

int main(){
    explainMap();
    return 0;
}
