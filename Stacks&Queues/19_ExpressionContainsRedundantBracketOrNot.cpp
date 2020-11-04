/* Approach : Stack

For redundancy two condition will arise while popping-

Point 1.  If immediate pop hits a open parenthesis ‘(‘, then we have found a duplicate parenthesis. For example, (((a+b))+c) has duplicate brackets around a+b. When we reach second “)” after a+b, we have “((” in the stack. Since the top of stack is a opening bracket, we conclude that there are duplicate brackets.
 
Point 2. If immediate pop doesn’t hit any operand(‘*’, ‘+’, ‘/’, ‘-‘) then it indicates the presence of unwanted brackets surrounded by expression. For instance, (a)+b contain unwanted () around a thus it is redundant.
(reference : gfg)             
 
 Time Complexity : O(n)
 Space Complexity : O(n)
*/
#include<bits/stdc++.h>
using namespace std;

bool isRedundant(string s){
	stack<char> st;
	int flag = true;
	for(int i = 0; i < (int)s.length(); i++){
		if(s[i] == ')'){
			if(st.top() == '(')     //if the immediate top is '(' this is similar to point 1 expained above
				return true;
			while(st.top() != '('){
				if(st.top() == '*' || st.top() == '/' || st.top() == '+' || st.top() == '-')
					flag = false;  // taking care of the point 2 stated above
				st.pop();
			}

			st.pop();
			if(flag == true)
				return true;
		}
		else
			st.push(s[i]);
	}
	return false;
}

int main(){
	string s; 
	cout<<"Enter String"<<endl;
	cin>>s;
	if(isRedundant(s))
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;
        return 0;
}
