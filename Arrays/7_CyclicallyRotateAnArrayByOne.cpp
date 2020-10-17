#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int> arr(n);
	    for(auto &it : arr) cin>>it;
	    int temp = arr[n-1];
	    for(int i = n-1; i > 0; i--){
	        arr[i] = arr[i-1];
	    }
	    arr[0] = temp;
	    for(int i : arr)
	       cout<<i<<" ";
	    cout<<endl;    
	}
	return 0;

