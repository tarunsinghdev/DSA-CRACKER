#include <bits/stdc++.h>
using namespace std;

//Time Complexity : O(n*logn)
//Space Complexity : O(1)

/*Approach 1
int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int> v(n);
	    for(auto &it : v) cin>>it;
	    int length = 1, ans = 1;
	    sort(v.begin(), v.end());
	    for(int i = 0; i < n-1; i++){
	       if(v[i] != v[i+1]){ 
    	        if(v[i+1] == v[i]+1){
    	           length++;
    	           ans = max(ans, length);
    	        }
    	        else 
    	           length = 1;
	       }
	            
	    }
	    cout<<ans<<endl;
	}
	return 0;
}
*/
//Approach 2 : 
//Time Complexity : O(n)
//Space Complexity : O(n)

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int> v(n);
	    for(auto &it : v) cin>>it;
	    unordered_set<int> st;
	    for(int i : v)
	       st.insert(i);
	    int longestStreak = 1;    
	    for(int nums : st){
	        if(!st.count(nums-1)){
	            int currNum = nums;
	            int currenStreak = 1;
	            while(st.count(currNum + 1)){
	                currNum++;
	                currenStreak++;
	            }
	            longestStreak = max(longestStreak, currenStreak);
	        }
	    }    
	    cout<<longestStreak<<endl;
	}
	return 0;
}
	    
	    
	    
	    
	    
	    
	    
	    
	    
	    
	    
	    
	    
	    
