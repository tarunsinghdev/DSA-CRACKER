#include <bits/stdc++.h>
using namespace std;
// Refer : https://www.youtube.com/watch?v=5Du2iSRrbEw
int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int> a(n);
	    for(auto &it : a) cin>>it;
	    int maxReach = a[0];
	    int step = a[0];
	    int jump = 1;
	    if(a[0] == 0){
	        cout<<-1<<endl;
	        continue;
	    }
	    for(int i = 1; i < n; i++){
	        if(i == n-1){
	            cout<<jump<<endl;
	            break;
	        }
	        maxReach = max(maxReach, i+a[i]);
	        step--;
	        if(step == 0){
	            jump++;
	            if(i >= maxReach){
	               cout<<-1<<endl;
	               break;
	            }
	            step = maxReach-i;
	        }
	    }
	}
	return 0;
}
