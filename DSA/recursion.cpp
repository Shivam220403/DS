#include <bits/stdc++.h>
using namespace std;

void print(int i,int n){
    if(i>n){
        return ;
    }
    cout<<"Shivam"<<endl;
    print(i+1,n);
}
void onetoN(int i,int n){
    if(i>n){
        return ;
    }
    cout<<i<<endl;
    onetoN(i+1,n);
}
void Nto1(int i,int n){
    if(i<1){
        return ;
    }
    cout<<i<<endl;
    Nto1(i-1,n);
}
void onetoN2(int i,int n){
    if(i<1){
        return ;
    }
    onetoN2(i-1,n);
    cout<<i<<endl;
}
void nto1back(int i,int n){
    if(n<i){
        return ;
    }
    nto1back(i+1,n);
    cout<<i<<endl;
}

void Summation(int i,int sum){        // Parameterised recursion
    if(i<1){
        cout<<sum<<endl;
        return ;
    }
    Summation(i-1,sum+i);
}
int Summation(int n){                 //Functional Recursion
    if(n==0) return 0;
    return n + Summation(n-1);
}
int fact(int n){
    if(n<1) return 1;
    return n*fact(n-1);
}


void ReverseArray(int arr[], int l, int r) {
    if (l >= r) {
        return;
    }
    swap(arr[l], arr[r]);
    ReverseArray(arr, l + 1, r - 1); 
}
int main(){
    //int n = 5;
    int array[] = {1,2,3,4,5};
    int n = int(sizeof(array)/sizeof(array[0]));
    //print(1,n);
    //onetoN(1,n);
    //Nto1(n,n);
    //onetoN2(n,n);
    //nto1back(1,n);
    //cout<<Summation(n);
    //cout<<fact(n);
    ReverseArray(array,0,n-1);
    for (int i = 0; i < n; i++) {
        cout << array[i] << " ";
    }
    return 0;
}