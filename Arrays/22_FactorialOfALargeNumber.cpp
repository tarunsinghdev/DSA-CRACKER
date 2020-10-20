#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        //Approach 1 : But fails for larger number
        
        // ll res = 1;
        // for(ll i = n; i > 0; i--){
        //     res *= i;
        // }
        
        //Approach 2 : Basic mathematics
        // long double sum = 0;
        // string res;
        // for(ll i = 1; i<=n; i++){
        //     sum += log(i);
        // }
        // res = to_string(round(exp(sum)));
        // string ans;
        // for(char ch : res){
        //     if(ch!= '.')
        //       ans += ch;
        //     else 
        //       break;
        // }
        // cout<<ans<<endl;
        
        //Aprroch 3 : The Interview Approach. We use array to store our result.
        
        int arr[100001] = {0};
        arr[0] = 1;
        int end = 0, carry = 0;
        for(int i = 2; i <=n ;i++){
            for(int j = 0; j <= end; j++){
                int mul = i*arr[j] + carry;
                arr[j] = mul%10;
                carry = mul/10;
            }
            while(carry!=0){
                arr[++end] = carry%10;
                carry = carry/10;
            }
        }
        for(int i = end; i>=0; i--)
           cout<<arr[i];
        cout<<endl;
    }
	return 0;
}
