#include <iostream>
using namespace std;

void SolidRectangle(int n){
    for (int i = 0; i < n; i++) {        //**** 
        for (int j = 0; j < n; j++) {    //**** 
            cout << "*";                 //**** 
        }                                //****
        cout << endl;
    }
}

void Triangle(int n){
    for (int i = 0; i < n; i++) {         //*
        for (int j = 0; j <= i; j++) {    //** 
            cout << "*";                  //*** 
        }                                 //**** 
        cout << endl;
    }
}

void NoTriangle(int n){
    for (int i = 1; i <= n; i++) {        //1
        for (int j = 1; j <= i; j++) {    //12
            cout << j;                    //123
        }                                 //1234
        cout << endl;
    }
}

void SameNoTriangle(int n){
    for (int i = 1; i <= n; i++) {         //1
        for (int j = 1; j <= i; j++) {     //22
            cout << i;                     //333
        }                                  //4444
        cout << endl;
    }
}

void IntertedTriangle(int n){
    for (int i = 1; i <= n; i++) {          //****
        for (int j = 0; j < n-i+1; j++) {   //*** 
            cout << "* ";                   //**
        }                                   //*
        cout << endl;
    }
}

void nNumberInvertedTriangle(int n) {
    for (int i = 0; i <= n; i++) {          //1234
        for (int j = 1; j < n-i+1; j++) {   //123
            cout << j<<" ";                 //12
        }                                   //1
        cout << endl;
    }
}

void nStarTriangle(int n) {
    for (int i = 0; i < n; i++) {                  //*
        for (int j = 0; j <n-i-1; j++) {          //***
            cout << " ";                         //*****
        }                                       //*******
        for (int j = 0; j <2*i+1; j++) {
            cout << "*";
        }

        cout << endl;
    }
}

void nStarInvertedTriangle(int n) {
    for (int i = 0; i < n; i++) {                   //*******
        for (int j = 0; j < i; j++) {                //*****
            cout << " ";                              //***
        }                                              //*
        for (int j = 0; j <2*n-2*i-1; j++) {
            cout << "*";
        }

        cout << endl;
    }
}

void Diamond(int n){
    for (int i = 0; i < n; i++) {                //*
        for (int j = 0; j <n-i-1; j++) {        //***
            cout << " ";                       //*****
        }                                       //***
        for (int j = 0; j <2*i+1; j++) {         //*
            cout << "*";
        }

        cout << endl;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            cout << " ";
        }
        for (int j = 0; j <2*n-2*i-1; j++) {
            cout << "*";
        }

        cout << endl;
    }
}

void HalfDiamond(int n){
    for (int i = 0; i < n; i++) {           //*
        for (int j = 0; j <= i; j++) {      //**
            cout << "*";                    //***
        }                                   //**
        cout << endl;                       //*
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < n-i+1; j++) {
            cout << "*";
        }
        cout << endl;
    }
}

void nBinaryTriangle(int n) {
    int start = 1;                      //1
    for (int i = 0; i < n; i++) {       //01
        if (i % 2 == 0) start = 1;      //101
        else start = 0;                 //0101
        for (int j = 0; j <= i; j++) {
            cout << start;
            start = 1- start;
        }
        cout << endl;
    }
}

void numberCrown(int n) {
    for (int i = 1; i <= n; i++) {              //1      1
        for (int j = 1; j <= i; j++) {          //12    21
            cout << j;                          //123  321
        }                                       //12344321
        for (int j = 1; j < 2*n-2*i+1; j++) {
            cout << " ";
        }
        
        for (int j = i; j >0 ; j--) {
            cout << j;
        }
        cout << endl;
    }
}

void NumberTriangle(int n) {
    int num = 1;                           //1
    for (int i = 1; i <= n; i++) {         //23
        for (int j = 1; j <= i; j++) {     //456
            cout << num;                   //78910
            num++;
        }
        cout << endl;
    }
}

void nLetterTriangle(int n) {
    for (int i = 0; i < n; i++) {                         //A
        for (char ch = 'A' ; ch <='A' + i; ch++) {        //AB
            cout << ch;                                   //ABC
        }                                                 //ABCD
        cout << endl;
    }
}

void InvertedNLetterTriangle(int n) {
    for (int i = 0; i < n; i++) {                                    //ABCD              
        for (char ch = 'A' ; ch <='A' + (n - i - 1); ch++) {         //ABC
            cout << ch;                                              //AB
        }                                                            //A
        cout << endl;
    }
}

void alphaRamp(int n) {
    for (int i = 0; i < n; i++) {           //A
        char ch = 'A' +i;                   //BB
        for (int j = 0; j <=i; j++) {       //CCC
            cout << ch;                     //DDDD
        }
        cout << endl;
    }
}

void alphaHill(int n) {
    for (int i = 0; i < n; i++) { 
        char ch = 'A';                             //A
        for (int j = 0; j <n-i-1; j++) {          //ABA
            cout << " ";                         //ABCBA
        }                                       //ABCDCBA

        int breakpoint = (2*i+1)/2;
        for (int j = 1; j <=2*i+1; j++) {
            cout << ch;
            if(j <=breakpoint) ch++;
            else ch--;
        }

        cout << endl;
    }
}

void alphaTriangle(int n) {
    for (int i = 1; i <= n; i++) {  
        char ch = 'A' + n - 1;                                  //D              
        for (int j = 1; j <= i; j++) {                          //DC
            cout << ch << " ";                                  //DCB
            ch--;                                               //DCBA
        }                                                           
        cout << endl;
    }
}

void HollowDimond(int n) {
    int inis = 0;                             //********
    for (int i = 0; i < n; i++) {             //***  *** 
        for (int j = 1; j <= n - i; j++) {    //**    ** 
            cout << "*";                      //*      *
        }                                     //*      *
        for (int j = 0; j < inis; j++) {      //**    **
            cout << " ";                      //***  ***
        }                                     //********
        for (int j = 1; j <= n - i; j++) {
            cout << "*";
        }

        inis += 2; 
        cout << endl;
    }

    inis -= 2;


    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= i + 1; j++) {
            cout << "*";
        }
        for (int j = 0; j < inis; j++) {
            cout << " ";
        }
        for (int j = 1; j <= i + 1; j++) {
            cout << "*";
        }

        inis -= 2;
        cout << endl;
    }
}

void butterfly(int n) {
    int spaces = 2*n - 2;                        //*      *
    for(int i = 1; i <= 2*n - 1;i++){            //**    **
        int stars = i;                           //***  ***
        if(i > n) stars = 2*n - i;               //********
        for(int j = 1; j <= stars; j++){         //***  ***
            cout << "*";                         //**    **
        }                                        //*      *
        for(int j = 1; j <= spaces; j++){
            cout << " ";
        }
        for(int j = 1; j <= stars; j++){
            cout << "*";
        }
        cout<< endl;
        if(i<n) spaces -=2;
        else spaces +=2;
    }
}

void HollowButterfly(int n) {
    int spaces = 2*n - 2;
    for(int i = 1; i <= 2*n - 1;i++){                               //*      *
        int stars = i;                                              //**    **
        if(i > n) stars = 2*n - i;                                  //* *  * *
        for(int j = 1; j <= stars; j++){                            //*  **  *
            if(j == 1 || j == stars || i == 1 || i == 2*n - 1){     //* *  * *
                cout << "*";                                        //**    **
            } else {                                                //*      *
                cout << " ";
            }
        }
        for(int j = 1; j <= spaces; j++){
            cout << " ";
        }
        for(int j = 1; j <= stars; j++){
            if(j == 1 || j == stars || i == 1 || i == 2*n - 1){
                cout << "*";
            } else {
                cout << " ";
            }
        }
        cout<< endl;
        if(i<n) spaces -=2;
        else spaces +=2;
    }
}

void HollowSquare(int n){
    for(int i = 0; i < n;i++){                          //****
        for(int j = 0; j<n;j++){                        //*  *
            if(i==0 || i==n-1 || j==0 || j == n-1){     //*  *
                cout<< "*";                             //****
            }else{
                cout<< " ";
            }
        }
        cout<<endl;
    }
    
}

void getNumberPattern(int n){
    for(int i = 0; i < 2*n- 1;i++){                             //4444444
        for(int j = 0; j<2*n- 1;j++){                           //4333334
            int top = i;                                        //4322234
            int left = j;                                       //4321234
            int right = (2*n - 2) - j;                          //4322234
            int down = (2*n - 2) - i;                           //4333334
            cout <<(n -min(min(top, down), min(left,right)));   //4444444
        }
        cout<<endl;
    }
    
}

int main() {
    int n;
    cin>>n;
    HollowSquare(n);

}