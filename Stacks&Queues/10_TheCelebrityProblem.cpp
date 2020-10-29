//Approach : Stack

//Time Complexity : O(n)
//Space Complexity : O(n)

class Solution {
    public:
    int celebrity(vector<vector<int> >& M, int n) {
        stack<int>st;
        for(int i = 0; i < n; i++)
             st.push(i);
        while(st.size() >= 2){
            int i = st.top();
            st.pop();
            int j = st.top();
            st.pop();
            if(M[i][j] == 1)    //i knows j => i is not a celebrity
               st.push(j);
            else
               st.push(i);    //i doesn't knows j => j is not a celebrity
        }     
        int potential_candidate = st.top();
        st.pop();
        for(int i = 0; i < n; i++){
            if(i != potential_candidate){
                if(M[i][potential_candidate] == 0 || M[potential_candidate][i] == 1)    //Verifying the potential_candidate's row and column
                       return -1;
            }
        }
        return potential_candidate;
    }
};

//Approach : Two Pointer Approach 

//Time Complexity : O(n)
//Space Complexity : O(1)

class Solution {
    public:
    
    int celebrity(vector<vector<int> >& M, int n) {
    int a = 0;
    int b = n - 1;
    
    while (a < b)
    {
        if (M[a][b])
            a++;
        else
            b--;
    }
    
    for (int i = 0; i < n; i++)  //Verifying if 'a' is celebrity
    {
        if ( (i != a) && ( M[a][i] ||  M[i][a] == 0 ) )
             return -1;
    }
 
    return a;
    }
};

