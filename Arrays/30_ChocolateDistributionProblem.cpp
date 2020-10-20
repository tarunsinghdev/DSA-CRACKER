#include <bits/stdc++.h>
using namespace std;
#define ll long long

//Time Complexity : O(nlogn)
//Space Complexity : O(1)

int main() {
    int t;
    cin>>t;
    while(t--){
        ll n, m;
        cin>>n;
        vector<ll> v(n);
        for(auto &it : v) cin>>it;
        cin>>m;
        sort(v.begin(), v.end());
        ll mn = LONG_MAX;
        for(int i = 0; i <n && i+m-1 < n; i++){
            mn = min(mn, v[i+m-1]-v[i]);
        }
        cout<<mn<<endl;
    }
	return 0;
}
