//Time Complexity : O(n)
//Space Complexity : O(n)

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin>>t;
	while(t--){
	    string s;
	    cin>>s;
	    stack<int> st;
	    int n = s.length();
	    int flag = 0;
	    for(int i = 0; i < n; i++){
	        if(s[i] == '(' or s[i] == '{' or s[i] == '[')
	               st.push(s[i]);
	       else{
	           if(!st.empty() && ((s[i] == ')' && st.top() == '(') or (s[i] == '}' && st.top() == '{') or (s[i] == ']' && st.top() == '[')))
	               st.pop();
	           else{ 
	               flag = 1; 
	               break;    //Breaks if a pair of opening bracket is not found at top of the stack and also it breaks when first element
		                 //is itself a closing bracket
	           }
	       }        
	    }
	    if(flag){              //Case when first element in the string is itself a closing bracket in that case stack will be empty and only in
		                  // this case the empty stack will print "not balanced"
	       cout<<"not balanced"<<endl;
	       continue;
	    } 
	    cout<<(st.empty() ? "balanced" : "not balanced")<<endl;
	}
	return 0;
}
