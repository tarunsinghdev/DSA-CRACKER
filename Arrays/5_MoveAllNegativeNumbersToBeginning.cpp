#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i = 0;  i< n; i++)
		cin>>arr[i];
	int j = 0;	
	for(int i = 0; i < n; i++){	        //Similar to partition logic in quicksort where pivot is 0.
		if(arr[i] < 0){
			swap(arr[j], arr[i]);
			j++;
		}
	}
	for(int i = 0; i < n; i++)
		cout<<arr[i]<<" ";
	cout<<endl;	
        return 0;
}
