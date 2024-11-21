#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++){
        cin>>arr[i];
    }
    int hash[13] = {0};                  // Maximum digit in arr could be 12
    for (int i = 0; i < n; i++){
        //store
        hash[arr[i]] += 1;
    }
    
    int q;
    cin>>q;
    while (q--){
        int number;
        cin>>number;
        //fetch
        cout<<hash[number]<<endl;
    }
    
    
    return 0;
}