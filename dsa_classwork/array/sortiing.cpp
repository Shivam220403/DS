#include <iostream>
using namespace std;

int main(){
    int arr[5] = {43,36,12,2,87};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<"Unsorted arry: "<<endl;
    for (int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    

    for(int i = 0; i <= n-1; i++){
        int j = i;
        while(j>0 && arr[j-1]>arr[j]){
          int temp =   arr[j-1];
          arr[j-1] = arr[j];
          arr[j] = temp;
          j--;
        }   
    }
    
    cout<<endl<<"Sorted arry: "<<endl;
    for (int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}