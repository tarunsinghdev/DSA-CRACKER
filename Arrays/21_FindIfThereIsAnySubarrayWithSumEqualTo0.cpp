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
	    unordered_set<int> st;
	    int  sum  = 0, flag  = 0;
	    for(int i = 0; i < n ; i++){
	        sum += v[i];
	        if(sum == 0 || st.count(sum)){
	           cout<<"Yes"<<endl;
	           flag = 1;
	           break;
	        }
	        else
	           st.insert(sum);
	    }
	    if(flag == 0)
	       cout<<"No"<<endl;
	    
	}
	return 0;
}
