/* Approch : Stack. Just push the operands encountered into the stack. When we encounter an operator
             pop last two elements from the stack and perform operation onto them and store their result
	     back into the stack.

Time Complexity : O(n)
Space Complexity : O(n)

*/

#include <bits/stdc++.h>
using namespace std;

bool isOperand(char c){
    return (c >= '0' && c <='9') ? true : false;
}

bool isOperator(char c){
    if(c == '+' || c == '-' || c == '*' || c == '/')
       return true;
    return false;       
}

int performOperation(char c, int op1, int op2){
    if(c == '+') return op1 + op2;
    if(c == '-') return op1 - op2;
    if(c == '*') return op1 * op2;
    if(c == '/') return op1 / op2;
}

int main() {
    int t;
    cin>>t;
    while(t--){
       string ex;
       cin>>ex;
       stack<int> st;
       for(int i = 0;  i < ex.length(); i++){
           if(isOperand(ex[i]) ){
               st.push(ex[i]-'0');
           }
           else if(isOperator(ex[i])){
               int op2 = st.top(); st.pop();
               int op1 = st.top(); st.pop();
               int result = performOperation(ex[i], op1, op2);
               st.push(result);
           }
       }
       cout<<st.top()<<endl;
    }
	
	return 0;
}
