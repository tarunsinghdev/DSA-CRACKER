#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int> v(n);
	    for(auto &it : v) cin>>it;
	    int i = 0, j = n-1, cnt  = 0;
	    while(i < j){
	        if(v[i] < v[j]){
	            i++;
	            v[i] += v[i-1];
	            cnt++;
	        }
	        else if(v[i] > v[j]){
	            j--;
	            v[j] += v[j+1];
	            cnt++;
	        }
	        else{
	            i++;
	            j--;
	        }
	    }
	    cout<<cnt<<endl;
	    
	}
	return 0;
}
