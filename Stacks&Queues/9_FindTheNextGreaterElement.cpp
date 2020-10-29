#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<ll> A(n), ans;
	    for(auto &it : A) cin>>it;
	    stack<ll> st;
	    for(int i = n-1; i >= 0; i--){
	        if(st.size() == 0)
	           ans.push_back(-1);
	       else if(st.size() > 0 && st.top() > A[i])
	           ans.push_back(st.top());
	       else if(st.size() > 0 && st.top() <= A[i]){
	           while(!st.empty() && st.top() <= A[i]){
	               st.pop();
	           }
	           if(st.empty())
	              ans.push_back(-1);
	           else
	              ans.push_back(st.top());
	       }
	       st.push(A[i]);
	    }
	    reverse(ans.begin(), ans.end());
	    for(auto x : ans)
	      cout<<x<<" ";
	    cout<<endl;   
	}
	return 0;
}
