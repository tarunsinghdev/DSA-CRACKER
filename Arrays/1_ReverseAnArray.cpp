#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    string s;
	    cin>>s;
	    int n = s.length();
	    for(int i = 0; i < n/2; i++){
	        swap(s[i],s[n-1-i]);
	    }
	    cout<<s<<endl;
	}
	return 0;
}
