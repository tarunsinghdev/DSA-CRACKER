/*Problem
Sage has two weapons p and q.
She has an array A of attacks. She wants to choose two indices i and j (1<=i<=j and j<=n) such that her power pA[i]+qA[j] is maximum.

Input:-
First line contains three integers n,p and q(1<=n<=10^5 and -10^9<=p,q<=10^9).
Second line contains n integers i.e the array of attacks (-10^9<=A[i]<=10^9).

Output:-
Maximum possible value for pA[i]+qA[j]. ## Example 1:-### Input:- 5 4 6
1 2 3 4 5 ### Output:- 50 ### Explanation:- Sage can choose index i=5 and j=5. Then the result will be :- 45 + 65 = 20+30 = 50.

Example 2:-
2 -2 3
1 2

Output:-
4
*/
#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define vi vector<int>
#define v3 vector<ll> 
#define pb push_back
#define FASTANDFURIOUS ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define For(i,n) for(ll i=0;i<n;i++)
#define pll pair <ll,ll>
#define pii pair <int,int>
#define fi first
#define se second
#define INF 3e18
signed main(){
    FASTANDFURIOUS;
    int t2=1;
    // cin>>t2;
    For(ti,t2){
        ll n,p,q;
        cin>>n>>p>>q;
        v3 v(n);
        For(i,n){
            cin>>v[i];
        }
        vector<pll> pref(n);
        pref[0].fi = v[0];
        pref[0].se = v[0];
        rep(i,1,n){
            pref[i].fi = max(pref[i-1].fi,v[i]);
            pref[i].se = min(pref[i-1].se,v[i]);
        }
        ll mx = 0LL,res=-INF;
        rep(i,0,n){
            ll a1 = p*1LL*pref[i].fi;
            ll a2 = p*1LL*pref[i].se;
            ll b1 = q*1LL*v[i];
            mx = max(a1,a2)+b1;
            res = max(res,mx);
        }
        cout<<res<<endl;
    }
}
