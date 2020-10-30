
/* Approach : In this stack is reversed using insertBottom function. When at first reverse function
              is called it empties the stack and hold value in the call stack. Now when we push elements
	      back into the stack we call insertBottom function so that elements gets pushed at the
	      bottom and we have our reversed stack.

Time Complexity : O(n*n)
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

void reverse_st(){
	if(!st.empty()){
		int b = st.top();
		st.pop();
		reverse_st();
		insertBottom(b);
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
	st.push(10); st.push(56); st.push(2); st.push(88);
	cout<<"Stack Before Reversal"<<endl;
	cout<<88<<" "<<2<<" "<<56<<" "<<10<<endl;
	reverse_st();
	cout<<"Reversed Stack"<<endl;
	display();
	return 0;
}
