// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
// Example 1:

// Input: n = 3
// Output: ["((()))","(()())","(())()","()(())","()()()"]

// Example 2:

// Input: n = 1
// Output: ["()"]

// Constraints:
//     1 <= n <= 8

class Solution {
public:
    
    vector<string> generateParenthesis(int n) {
        vector<string> answer;
        string s="";
        generate(s,n,n,answer);
        return answer;
    }
    
    void generate(string &s,int open,int close,vector<string> &answer){
        
        if(open==0 and close==0)
        {
            answer.push_back(s);
            return;
        }
        if(open>0)
        {
            s.push_back('(');
            generate(s,open-1,close,answer);
            s.pop_back();
        }
        if(close>0){
            if(open<close)
            {
                s.push_back(')');
                generate(s,open,close-1,answer);
                s.pop_back();
            }
        }
    }
};
