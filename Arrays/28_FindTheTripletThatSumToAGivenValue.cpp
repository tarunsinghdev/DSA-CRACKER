#include <bits/stdc++.h>
using namespace std;

//Time Complexity : O(n*n)
//Space Complexity : O(1)

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n, x;
	    cin>>n>>x;
	    vector<int> a(n);
	    for(auto &it : a) cin>>it;
	    int flag = 0, sum = 0;
	    sort(a.begin(), a.end());
	    for(int i = 0; i < n-2; i++){
	        int j = i+1, k = n-1;
	        while(j < k){
	            sum = a[i] + a[j] + a[k];
	            if(sum > x){
	                k--;
	            }
	            else if(sum < x)
	                j++;
	            else{
	                cout<<1<<endl;
	                flag = 1;
	                break;
	            }
	                 
	        }
	        if(flag)
	           break;
	    }
	    if(flag == 0){
	       cout<<0<<endl;
	       continue;
	    }
	}
	return 0;
}
