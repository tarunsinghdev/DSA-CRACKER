/* Approach : Stack

Time Complexity : O(n)
Space Complexity : O(n)
*/

#include<bits/stdc++.h>
using namespace std;

stack<int> st;

void insertBottom(int x){
	if(st.empty())
		st.push(x);
	else{
		int a = st.top();
		st.pop();
		insertBottom(x);      //due to recursion, 'a' value gets on hold in the call stack and
		                      //we use this opportunity to insert back all the elements.

		st.push(a);
	}
}

void display(){
	while(!st.empty()){
		cout<<st.top()<<" ";
		st.pop();
	}
	cout<<endl;
}
		


int main(){
        int x;	
	st.push(10); st.push(56); st.push(2); st.push(88);
	cout<<"Enter element to be inserted at the bottom of the stack"<<endl;
	cin>>x;
	insertBottom(x);
	display();
	return 0;
}
