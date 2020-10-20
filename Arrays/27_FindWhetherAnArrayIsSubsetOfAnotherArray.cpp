#include <bits/stdc++.h>
using namespace std;

//Time Complexity : O(mlogm + nlogn)
//Space Complexity : O(1)

int main() {
	int t;
	cin>>t;
	while(t--){
	    int m, n;
	    cin>>m>>n;
	    int flag = 0;
	    vector<int> a1(m), a2(n);
	    for(auto &it : a1) cin>>it;
	    for(auto &it : a2) cin>>it;
	    if(a2.size() > a1.size()){
	       cout<<"No"<<endl;
	    }
	    else{
	        sort(a1.begin(), a1.end());
	        sort(a2.begin(), a2.end());
	        int i = 0, j = 0;
	        while(i < m && j < n){
	            if(a1[i] < a2[j])
	                i++;
	            else if(a1[i] == a2[j]){
	                i++; 
	                j++;
	            }
	            else{
	                flag = 1;
	                break;
	            }
	        }
	        if(flag)
	            cout<<"No"<<endl;
	        else
	            cout<<"Yes"<<endl;
	    }    
	}
	return 0;
}
