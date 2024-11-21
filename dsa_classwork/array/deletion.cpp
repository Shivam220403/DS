#include <iostream>
using namespace std;

int main(){
    int n = 5;
    int arr[10]={1,2,3,4,5};
    int index = 2;
    
    if(index <= n || index >= 0){
        for(int i = index; i < n; i++){
        arr[i] = arr[i+1];
        }
        n--;

        for (int i = 0; i < n; i++){
            cout<<arr[i]<<" ";
        }
        
    }
    else{
        cout<<"Invalid Input";
    }
    cout<<endl;
    return 0;
}
