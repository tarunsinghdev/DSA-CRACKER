#include <bits/stdc++.h>
using namespace std;

//Time Complexity : O(n)
//Space Complexity : O(1)

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int> v(n);
	    for(auto &it : v) cin>>it;
	    int K;
	    cin>>K;               //Careful : Don't confuse with 'K' and 'k'
	    int cnt = 0;
	    
	    for(int i : v)       //Counts the smallest elements less or equal to K
	        if(i <= K)
	           cnt++; 
	           
	    int ans = INT_MAX;
	    for(int k = 0; k < n-cnt+1; k++){     //Counts for every window the elements that are greater in it
		                                   and that'll be ultimately equal to the no. of swaps required.
	        int bad = 0;
	        for(int i = k; i <= cnt+k-1; i++ ){
	           if(v[i] > K)
	              bad++;
	        }
	        ans = min(ans, bad); 
	    }
	    cout<<ans<<endl;
	}
	return 0;
}
