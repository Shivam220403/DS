#include<iostream>
using namespace std;

int main(){
    	int arr[5] = {43,36,12,2,87};
    	int n = sizeof(arr)/sizeof(arr[0]);
	int element;
	cout<<"Enter the element you want to search: ";
	cin>>element;
	for(int i = 0;i<n;i++){
		if(arr[i] == element){
			cout<<"The Element << element" << "is at index " << i<<endl;
		}
	}
		
    return 0;
}
