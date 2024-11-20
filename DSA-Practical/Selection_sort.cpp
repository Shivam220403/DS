#include <bits/stdc++.h>
using namespace std;

void selection_sort(int arr[],int n){
    for (int i = 0; i < n-2; i++){
        int min = i;
        for (int j = i; j <= n-1; j++){
            if(arr[j] < arr[min]){
                min = j;
            }
        }
        int temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
}


int main(){
    int arr[] = {13,46,24,52,20,9};
    int n = int(sizeof(arr)/sizeof(arr[0]));

    selection_sort(arr,n);
    for (int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}