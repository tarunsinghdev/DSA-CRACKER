#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cout<<"Enter array size"<<endl;
	cin>>n;
	int arr[n];
	cout<<"Enter array"<<endl;
	for(int i = 0; i < n; i++)
		cin>>arr[i];
	int mn = INT_MAX, mx = INT_MIN;
	for(int i = 0; i < n; i++){
		if(arr[i] < mn)
			mn = arr[i];
		if(arr[i] > mx)
			mx = arr[i];
	}
	cout<<"Minimum element found :"<<mn<<endl;
	cout<<"Maximum element found :"<<mx<<endl;
	return 0;
}

