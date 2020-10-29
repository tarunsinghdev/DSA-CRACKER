//Time Complexity : O(n)
//Space Complexity : O(n)

void reverse(char str[], int len)
{
    stack<int> st;
    for(int i = 0; i < len; i++){
        st.push(str[i]);
    }
         
    for(int i = 0; i < len; i++){
        str[i] = st.top();
        st.pop();
    }

}
