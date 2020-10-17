#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n ;
	    cin>>n;
	    vector<int>a(n);
	    for(auto &it : a) cin>>it;
	    int pref = 0;
	    int max_sum = INT_MIN;
	    for(int i = 0;  i < n ; i++){
	        pref += a[i];
	        max_sum = max(max_sum, pref);
	        if(pref<0)
	           pref = 0;
	    }
	    cout<<max_sum<<endl;
	}
	return 0;
}
