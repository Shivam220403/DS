#include <bits/stdc++.h>
using namespace std;

void bubble_sort(int arr[],int n){
    for (int i = n-1; i >= 0; i--){
        int didSwap = 0;
        for (int j = 0; j <= i-1; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
                didSwap = 1;
            }
        }
        if (didSwap == 0){
            break;
        }
    }
}


int main(){
    int arr[] = {13,46,24,52,20,9};
    int n = int(sizeof(arr)/sizeof(arr[0]));

    bubble_sort(arr,n);
    for (int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}