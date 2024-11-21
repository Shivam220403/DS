#include <iostream>
using namespace std;

int main(){
    int arr[5] = {43,36,12,2,87};
    int n = sizeof(arr)/sizeof(arr[0]);

    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}
