#include<iostream>
#include<vector>
using namespace std;

static int counter = 0;
vector<int> memo(100, -1);

// int fib(int n){
//     counter++;
//     if(memo[n] != -1){
//         return memo[n];
//     }
//     if(n == 0 || n == 1){
//         return n;
//     }
//     memo[n] = fib(n-1) + fib(n-2);
//     return memo[n];
// }

// Bottom-UP
int fib(int n){
    vector<int> fibList;
    fibList.push_back(0);
    fibList.push_back(1);
    
    for(int i = 2; i <= n; i++){
        counter++;
        fibList[i] = fibList[i-1] + fibList[i-2];
    }
    return fibList[n];
}


int main(){
    int n =7;
    cout << "\nFib of "<< n << " = " << fib(n);
    cout << "\n\n Counter: " << counter <<endl;
    return 0;
}